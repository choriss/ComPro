#!/usr/bin/env python3
"""
expand_includes.py

# 概要
指定した C/C++ ソースファイルについて、`#include "file"` で書かれたファイルを
その中身で再帰的に展開して単一ファイルを出力します。
- `#include <...>` はそのまま残す
- 同じファイルは一度だけ展開（include-once 相当）して無限ループを防ぐ
- 元ファイル毎の相対パスを考慮して検索（include_dirs, 親ディレクトリ優先）
- 見つからない場合は警告を出して元の行をそのまま残す

注意: プロジェクト固有のマクロや条件付き include の意図を完全に再現するものではありません。
"""

import argparse
import os
import re
import sys
from typing import List, Set, Optional

INCLUDE_REGEX = re.compile(r'^[ \t]*#\s*include\s*"([^"]+)"', re.MULTILINE)

def find_include_file(name: str, current_dir: str, include_dirs: List[str]) -> Optional[str]:
    """名前を current_dir -> include_dirs の順で探して絶対パスを返す。見つからなければ None。"""
    # まず現在のファイルのディレクトリから
    cand = os.path.abspath(os.path.join(current_dir, name))
    if os.path.isfile(cand):
        return cand
    # 次に include_dirs を順に
    for d in include_dirs:
        cand = os.path.abspath(os.path.join(d, name))
        if os.path.isfile(cand):
            return cand
    return None

def expand_file(path: str, include_dirs: List[str], visited: Set[str], depth: int = 0) -> str:
    """
    ファイル path の内容を読み、#include "..." を再帰的に展開して返す。
    visited は絶対パスの集合で、既に展開済みのファイルを格納する（重複展開防止）。
    """
    indent = '  ' * min(depth, 10)
    abs_path = os.path.abspath(path)
    if abs_path in visited:
        # 既に展開済みなので、注釈を残して何も展開しない（include-once 相当）
        return f'/* Skipped already expanded file: {abs_path} */\n'
    visited.add(abs_path)

    try:
        with open(abs_path, 'r', encoding='utf-8') as f:
            text = f.read()
    except Exception as e:
        sys.stderr.write(f'Warning: failed to read "{abs_path}": {e}\n')
        return f'/* Failed to read include file: {path} */\n'

    current_dir = os.path.dirname(abs_path)

    def _repl(match: re.Match) -> str:
        included_name = match.group(1)
        found = find_include_file(included_name, current_dir, include_dirs)
        if not found:
            # 見つからなかったら元の行を残し警告を出す
            sys.stderr.write(f'Warning: include file not found: "{included_name}" included from "{abs_path}"\n')
            return match.group(0)  # 元の #include "..." 行
        # 見つかったので再帰展開
        header_comment = (
            f'/* Begin expanded file: {included_name} (resolved: {found}) */\n'
            f'#line 1 "{found}"\n'
        )
        body = expand_file(found, include_dirs, visited, depth + 1)
        footer_comment = f'\n#line 1 "{abs_path}"\n/* End expanded file: {included_name} */\n'
        return header_comment + body + footer_comment

    # `#include "..."` をすべて置換（再帰的にコールされる）
    expanded = re.sub(INCLUDE_REGEX, _repl, text)
    return expanded

def main():
    parser = argparse.ArgumentParser(
        description='Expand #include "file" into source by inlining quoted includes (recursive).'
    )
    parser.add_argument('input', help='入力ソースファイル（例: src/main.cpp）')
    parser.add_argument('-I', '--include', action='append', default=[], help='追加のインクルード検索パス (can be repeated)')
    parser.add_argument('-o', '--output', default=None, help='出力ファイル（指定しない場合は stdout）')
    parser.add_argument('--allow-multiple', action='store_true',
                        help='同一ファイルを複数回展開する（デフォルトは一度だけ展開）')
    args = parser.parse_args()

    input_path = os.path.abspath(args.input)
    include_dirs = [os.path.abspath(d) for d in args.include]
    # 既定で入力ファイルのディレクトリを先頭に含める（通常のコンパイラの動作に近づける）
    input_dir = os.path.dirname(input_path)
    if input_dir not in include_dirs:
        include_dirs.insert(0, input_dir)

    visited: Set[str] = set()

    # expand_file は visited を使う。--allow-multiple が指定されたら visited を一時的に無視する振る舞いにする
    if args.allow_multiple:
        # シンプルに visited を別扱いにして、展開したいたびにコピーしない（つまり何もせず）
        visited_for_top = set()
    else:
        visited_for_top = visited

    result = expand_file(input_path, include_dirs, visited_for_top, depth=0)

    if args.output:
        os.makedirs(os.path.dirname(os.path.abspath(args.output)) or '.', exist_ok=True)
        with open(args.output, 'w', encoding='utf-8') as f:
            f.write(result)
    else:
        sys.stdout.write(result)

if __name__ == '__main__':
    main()
