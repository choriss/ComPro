#include <bits/stdc++.h>

using namespace std;

//templates

// ---------- 基本 ----------
#define ll long long
#define ull unsigned long long
#define ld long double

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pl pair<ll,ll>
#define vecll vector<ll>
#define vecpll vector<pll>
#define vecs vector<string>
#define cinvec(vec,type,size) vector<type> vec(size); for(ll i=0;i<size;i++) cin >> vec[i];

using i128 = __int128;

// ---------- for 系 ----------
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i,n) for(ll i=1;i<=(ll)(n);i++)
#define rrep(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define repi(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)

// ---------- コンテナ操作 ----------
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

// ---------- sort ----------
#define srt(x) sort(all(x))
#define rsrt(x) sort(rall(x))

// ---------- vector ----------
#define sumall(x) std::reduce(all(x))
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))

// ---------- 出力補助 ----------
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define print(a) cout << (a) << "\n"

// その他
#define append push_back

//デバッグ用
#define dbg cout << "DEBUG" << endl


using pquell = priority_queue<ll>;

#define INFLL 1LL<<62

//累積和
template <class T = long long>
struct CumulativeSum {
private:
    // pref[i] = 先頭から i 個分の和
    std::vector<T> pref;
    ll mod;
    ll m;

public:
    CumulativeSum() {
        pref.push_back(T(0)); // pref[0] = 0
        m = 0;
    }

    CumulativeSum(ll M){
        pref.push_back(T(0)); // pref[0] = 0
        mod = M;
        m = 1;
    }


    // 要素を末尾に追加
    void push_back(T x) {
        if(m){
            pref.push_back((pref.back() + x)%mod);
        }else{
            pref.push_back(pref.back() + x);
        }
        
    }

    // 区間 [l, r] の和を返す
    T range_sum(int l, int r) const {
        //assert(0 <= l && l <= r && r < (int)pref.size());
        if (l<0 && r<0) return 0;
        if (l>=(int)pref.size()-1) return 0;
        if (l<0) l=0;
        if (r>=(int)pref.size()-1) r=(int)pref.size()-2;
        if(m){
            return (pref[r+1] - pref[l]+mod)%mod;
        }else{
            return pref[r+1] - pref[l];
        }
        
    }

    // 現在の要素数
    int size() const {
        return (int)pref.size() - 1;
    }
};


constexpr long long INF = (1LL << 60);

// 辺の情報
struct Edge
{
	// 行先
	int to;

	// コスト
	int cost;
};

using Graph = std::vector<std::vector<Edge>>;

// { distance, from }
using Pair = std::pair<long long, int>;

// ダイクストラ法 (1.1 基本実装)
// distances は頂点数と同じサイズ, 全要素 INF で初期化しておく
void Dijkstra(const Graph& graph, std::vector<long long>& distances, int startIndex)
{
	// 「現時点での最短距離, 頂点」の順に取り出す priority_queue
	// デフォルトの priority_queue は降順に取り出すため std::greater を使う
	std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> q;
	q.emplace((distances[startIndex] = 0), startIndex);

	while (!q.empty())
	{
		const long long distance = q.top().first;
		const int from = q.top().second;
		q.pop();

		// 最短距離でなければ処理しない
		if (distances[from] < distance)
		{
			continue;
		}

		// 現在の頂点からの各辺について
		for (const auto& edge : graph[from])
		{
			// to までの新しい距離
			const long long d = (distances[from] + edge.cost);

			// d が現在の記録より小さければ更新
			if (d < distances[edge.to])
			{
				q.emplace((distances[edge.to] = d), edge.to);
			}
		}
	}
}

// int main()
// {
// 	// N 個の街, M 本の道路
// 	int N, M;
// 	std::cin >> N >> M;

// 	// N 頂点のグラフ
// 	Graph graph(N);
// 	for (int i = 0; i < M; ++i)
// 	{
// 		int A, B, C;
// 		std::cin >> A >> B >> C;
// 		--A; --B;
// 		graph[A].push_back({ B, C });
// 		graph[B].push_back({ A, C });
// 	}

// 	// 街[0] から各街への最短距離
// 	std::vector<long long> distancesFrom1(N, INF);
// 	Dijkstra(graph, distancesFrom1, 0);

// 	// 街[N-1] から各街への最短距離
// 	std::vector<long long> distancesFromN(N, INF);
// 	Dijkstra(graph, distancesFromN, (N - 1));

// 	// 街[i] を経由して街[N-1] まで移動するときにかかる時間の最小値
// 	for (int i = 0; i < N; ++i)
// 	{
// 		std::cout << (distancesFrom1[i] + distancesFromN[i]) << '\n';
// 	}
// }

int mex(vector<ll> &a){
    ll ok = -1;
    ll ng = a.size();
    ll mid;
    while(ng-ok > 1){
        mid = (ok+ng)/2;
        if(a[mid] == mid){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    return ng;
}

int main(){
    //(=^・^=)←猫(笑)

    // rep(i,11){
    //     rep(j,11){
    //         cout << (i^j) << " ";
    //     }
    //     cout << endl;
    // }


    ll T;
    cin >> T;
    rep(h,T){
        ll a,b,C;
        cin >> a >> b >> C;
        set<ll> ansA;
        set<ll> ansB;
        rep(i,a){
            ansA.insert(i);
        }
        rep(i,b){
            ansB.insert(i);
        }
        set<ll> seen;
        for(int x:ansA){
            for(int y:ansB){
                seen.insert(x^y);
            }
        }
        vector<ll> memo;
        for(int x:seen){
            memo.append(x);
        }
        srt(memo);
        ll cnt = min(a,b);
        if(mex(memo) > C){
            no;
            continue;
        }
        if(a==0 && b == 0 && C == 0){
            yes;
            print(0);
            print(0);
            continue;
        }
        while(mex(memo) != C){
            //Aの方に追加を試みる
            if(cnt==2027){
                break;
            }
            if(a!= cnt && ansA.count(cnt) == 0){
                set<ll> m;
                for(int x:ansB){
                    m.insert(x ^cnt);
                }
                if(m.count(C) == 1){
                    //アカン
                }else{
                    ansA.insert(cnt);
                    for(int x:m){
                        memo.append(x);
                    }
                }
            }
            
            //Bの方に追加を試みる
            if(b!= cnt && ansB.count(cnt) == 0){
                set<ll> m;
                for(int x:ansA){
                    m.insert(x ^cnt);
                }
                if(m.count(C) == 1){
                    //アカン
                }else{
                    ansB.insert(cnt);
                    for(int x:m){
                        memo.append(x);
                    }
                }
            }
            cnt++;
            srt(memo);
            memo.erase(unique(memo.begin(), memo.end()), memo.end());
            // rep(i,memo.size()){
            //     cout << memo[i] << " ";
            // }
            // cout << endl;
            // print(mex(memo));

        }
        if(cnt==2027){
            no;
            continue;
        }
        yes;
        cout << ansA.size() << " ";
        for(int x:ansA){
            cout << x << " ";
        }
        cout << endl;
        cout << ansB.size() << " ";
        for(int x:ansB){
            cout << x << " ";
        }
        cout << endl;

    }
 
}

/*
・にぶたんの判定関数はf(mid)
・C(N,K)に制限があるからと言ってKが小さいとは思うな...(KがNに近いときとかあるよね)
・オーバーフロー注意！！←誤判定のもと
・浮動小数点の誤差に注意！！(掛け算して比較推奨・比較するときにi64超えてない？)
・お前そのmultiset本当に必要？(vector推奨)
・再帰的に処理できないか
・グラフビジュアライザー(https://gemini.google.com/share/6a5c1ef7af18)
・頂点倍加(https://gemini.google.com/share/f793368fdc34)
・グリッドビジュアライザー(https://gemini.google.com/share/c36d0cc980d2)
・めぐる式にぶたん(https://zenn.dev/forcia_tech/articles/20191223_advent_calendar)
・多角形面積(https://gemini.google.com/app/009772a4dcfc3785)
・遅延セグメント木チートシート(https://betrue12.hateblo.jp/entry/2020/09/23/005940)
*/

/*MLE REチェックリスト
【競プロ特化】RE / MLE 撲滅チェックリスト

■ 1. 探索アルゴリズム（BFS / DFS）の罠
[ ] 始点・初期値のハードコードをしていないか？（最重要）
    - q.push(0) や dfs(0) のように固定値を直接書いていないか。
    - 動的に開始位置が変わる場合、正しく変数を渡せているか。
[ ] 経路復元の終了条件は絶対に到達可能か？
    - while (current != -1) で戻る際、ルートが繋がっておらず初期値(-2等)になっていないか。
    - 配列外アクセス(RE)から無限ループ(MLE)の最悪コンボに注意。
[ ] 訪問済みのフラグ立ては「キューに入れる瞬間」か？
    - 取り出す瞬間にフラグを立てると、キューに同じ頂点が何度も積まれてしまいMLE/TLEになる。

■ 2. 配列・インデックス（REの親玉）
[ ] 0-indexed と 1-indexed が混ざっていないか？
    - 頂点数 N のとき、配列外の G[N] にアクセスしていないか。
    - 入力時の u--; v--; などのデクリメント忘れはないか。
[ ] 配列が空のときに .front() や [0] を叩いていないか？
    - 条件を満たすものが1つもないケースでの空コンテナアクセス。
[ ] グリッド探索での境界チェックの順序は正しいか？
    - 範囲チェック (nx < 0 || ...) を配列参照 grid[nx][ny] よりも先に書いているか。

■ 3. グラフの構造・再帰周り（MLE / RE）
[ ] 再帰（DFS）のベースケース（終了条件）は抜けていないか？
    - 終了条件抜けは無限再帰となり Stack Overflow (RE) を引き起こす。
[ ] 自己ループや多重辺に対する考慮はあるか？
    - 単純無向グラフの保証がない場合、u == v で無限ループしないか。
[ ] 巨大な配列をローカル変数で宣言していないか？
    - 関数内で int dp[10000][10000]; を宣言すると Stack Overflow になる。

■ デバッグ時のヒント
RE と MLE が同時に出た場合、「配列外のゴミデータを参照した結果、無限ループの終了条件を一生満たせなくなり、配列に push_back し続けている」可能性が非常に高いです。whileの終了条件とインデックスの値を真っ先に確認しましょう。
*/

/*データ構造とか
・値の追加削除高速+x以下の値は何個?クエリ→フェニック木をお使いください
sorted multisetでもいいよ
*/
