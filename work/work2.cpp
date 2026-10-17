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

template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}

// int main() {
//   foreach_comb(10, 6, [](int *indexes) {
//     std::cout << indexes[0] << ',' << indexes[1] << ',' << indexes[2] << std::endl;
//   });
// }

int main(){
    // 101+ 102- 103* 104/
    ll ans = 0;
    ll cnt = 0;
    vector<vector<ll>> a;
    foreach_comb(30, 4, [&](int *indexes) {

        set<ll> st;
        rep(h,64){
            vector<ll> ns = {100+h/16 , 100+(h/4) % 4 , 100+h%4};
            rep(i,4){
                ns.append(indexes[i]+1);
            }
            srt(ns);
            do{
                ll f = 1;
                vector<double> res;
                if(ns[0]>=100||ns[1]>=100 ){
                    continue;
                }
                rep(i,7){
                    if(ns[i]>=100){
                        if(res.size()>=2){
                            double a = res[res.size()-1];
                            double b = res[res.size()-2];
                            res.pop_back();
                            res.pop_back();
                            if(ns[i] == 100){
                                res.append(a+b);
                            }else if(ns[i] == 101){
                                res.append(a-b);
                            }else if(ns[i] == 102){
                                res.append(a*b);
                            }else{
                                res.append(a/b);
                            }
                        }else{
                            f = 0;
                            break;
                        }
                    }else{
                        res.append(ns[i]);
                    }
                }
                
                if(f && res.size()==1 && ((ll)(res[0] * 100000)) % 100000 == 0){
                    st.insert((ll)res[0] );
                    // print((ll)res[0]);
                }
            }while(next_permutation(all(ns)));
        }
        ll sc = 0;
        while(true){
            if(st.count(sc+1)){
                sc++;
            }else{
                break;
            }
        }
        if(cnt % 100 == 0){
            rep(i,4){
                cout << indexes[i]+1 << " ";
                
            }
            cout << endl;
        }

        // cout << "num "<<sc << endl;
        vector<ll> x;
        x.append(sc);
        rep(i,4){
            x.append(indexes[i]+1);
        }
        a.append(x);
        cnt++;
    });
    rsrt(a);
    rep(i,100){
        cout << a[i][0] << ":";
        rep1(j,4){
            cout << a[i][j] << " " ;
        }
        cout << endl;
    }
}

/*
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

/*データ構造とか
・値の追加削除高速+x以下の値は何個?クエリ→フェニック木をお使いください
sorted multisetでもいいよ
*/
