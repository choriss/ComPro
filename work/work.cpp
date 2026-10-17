//Compile Options
# pragma GCC target("avx2")
# pragma GCC optimize("O3")
# pragma GCC optimize("unroll-loops")

//libraries
#include <bits/stdc++.h>
#include <atcoder/all>
#include <ext/pb_ds/assoc_container.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/algorithm/string/replace.hpp>
namespace mp = boost::multiprecision;
using namespace std;
using namespace atcoder;
using namespace __gnu_pbds;

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


using mint = modint998244353;


template <class T>
void println_decimal(T value, int digits) {
    std::cout << std::fixed << std::setprecision(digits) << value << '\n';
}
template <class T>
void print_decimal(T value, int digits) {
    std::cout << std::fixed << std::setprecision(digits) << value <<" ";
}


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

#define CS2D_BUILD(cs, a) \
    int cs##_H = (a).size(); \
    int cs##_W = ((a).empty() ? 0 : (a)[0].size()); \
    vector<vector<long long>> cs(cs##_H + 1, vector<long long>(cs##_W + 1, 0)); \
    for (int i = 0; i < cs##_H; i++) \
        for (int j = 0; j < cs##_W; j++) \
            cs[i + 1][j + 1] = (a)[i][j] \
                             + cs[i][j + 1] \
                             + cs[i + 1][j] \
                             - cs[i][j];

#define CS2D_QUERY(cs, a, b, c, d) \
    ((cs)[(c) + 1][(d) + 1] \
    - (cs)[(a)][(d) + 1] \
    - (cs)[(c) + 1][(b)] \
    + (cs)[(a)][(b)])


// const int N = 2*pow(10,4);

// vector<bool> isp(N+1, true);

// void sieve() {
//   isp[0] = false;
//   isp[1] = false;
//   for (int i=2; pow(i,2)<=N; i++) {
//     if (isp[i]) for(int j=2; i*j<=N; j++) isp[i*j] = false;
//   }
// }


//素因数分解
// const int N = 200000; // 必要に応じて変更
// vector<int> minp(N + 1);

//最小素因数の前計算
// void sieve_minp() {
//     for (int i = 0; i <= N; i++) minp[i] = i;
//     minp[0] = 0;
//     minp[1] = 1;

//     for (int i = 2; i * i <= N; i++) {
//         if (minp[i] == i) { // i が素数
//             for (int j = i * i; j <= N; j += i) {
//                 if (minp[j] == j) minp[j] = i;
//             }
//         }
//     }
// }

// x の素因数分解を返す
// 戻り値: {素因数, 指数} の vector
// vector<pair<ll, ll>> pfWithMinp(ll x) {
//     vector<pair<ll, ll>> res;
//     while (x > 1) {
//         ll p = minp[x];
//         ll cnt = 0;
//         while (x % p == 0) {
//             x /= p;
//             cnt++;
//         }
//         res.push_back({p, cnt});
//     }
//     return res;
// }



ll exp10(ll n){
    ll ans= 1;
    rep(i,n){
        ans*=10;
    }
    return ans;
}
ll expo(ll a, ll b){
    ll ans = 1;
    rep(i,b){
        ans*=a;
    }
    return ans;
}
ll expo(int a, ll b){
    ll ans = 1;
    rep(i,b){
        ans*=a;
    }
    return ans;
}
i128 expo(i128 a, ll b){
    i128 ans = 1;
    rep(i,b){
        ans*=a;
    }
    return ans;
}
unsigned GetDigit(unsigned num){
	unsigned digit = 0;
	while(num != 0){
		num /= 10;
		digit++;
	}
	return digit;
}

template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}


struct triplet {
    ll first, second, third;

    // デフォルトコンストラクタ
    triplet() : first(0), second(0), third(0) {}
    triplet(ll a, ll b, ll c) : first(a), second(b), third(c) {}

    // === 辞書順比較（std::sortでそのまま使える）===
    bool operator<(const triplet& other) const {
        if (first != other.first) return first < other.first;
        if (second != other.second) return second < other.second;
        return third < other.third;
    }

    // === 等価判定（set / map / 重複除去用）===
    bool operator==(const triplet& other) const {
        return first == other.first
            && second == other.second
            && third == other.third;
    }

    // === 各キー単体での比較用（ラムダ無しで使える）===
    static bool cmp_first(const triplet& a, const triplet& b) {
        return a.first < b.first;
    }
    static bool cmp_second(const triplet& a, const triplet& b) {
        return a.second < b.second;
    }
    static bool cmp_third(const triplet& a, const triplet& b) {
        return a.third < b.third;
    }

    // === pair / tuple 的に扱いたいとき用 ===
    auto tie() const {
        return std::tie(first, second, third);
    }
};

template <class T>
class OffsetVector {
private:
    int N;                 // 許可する最大絶対値
    int offset;            // 添字補正用
    std::vector<T> data;   // 実体

public:
    // -N ～ N を許可
    explicit OffsetVector(int N_, const T& init = T())
        : N(N_), offset(N_), data(2 * N_ + 1, init) {}

    // 添字アクセス（範囲チェックあり）
    T& at(int idx) {
        if (idx < -N || idx > N)
            throw std::out_of_range("Index out of range");
        return data[idx + offset];
    }

    const T& at(int idx) const {
        if (idx < -N || idx > N)
            throw std::out_of_range("Index out of range");
        return data[idx + offset];
    }

    // 添字アクセス（範囲チェックなし）
    T& operator[](int idx) {
        return data[idx + offset];
    }

    const T& operator[](int idx) const {
        return data[idx + offset];
    }

    int min_index() const { return -N; }
    int max_index() const { return N; }
    int size() const { return data.size(); }
};

constexpr std::string ToBaseN(long long n, const unsigned int base)
{
    ll f = 1;
    if(n<0){
        f = -1;
        n *= -1;
    }
    // cout << n << endl;
	if ((base < 2) || (36 < base))
	{
		throw std::invalid_argument{ "base must be in the range [2, 36]." };
	}

	constexpr char Digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string s;

	do
	{
		s.push_back(Digits[n % base]);
		n /= base;
	} while (n);

	std::ranges::reverse(s);
	if(f == 1)return s;
    else return "-"+s;
}




ll digrev(ll n){
    string s = to_string(n);
    ranges::reverse(s);
    return stoll(s);
}

void merge_intervals(vector<pair<ll,ll>>& seg,
                     vector<pair<ll,ll>>& res){
    if(seg.empty()) return;

    sort(seg.begin(), seg.end());

    ll L = seg[0].first;
    ll R = seg[0].second;

    for(int i = 1; i < seg.size(); i++){
        if(seg[i].first > R){
            res.push_back({L,R});
            L = seg[i].first;
            R = seg[i].second;
        }else{
            R = max(R, seg[i].second);
        }
    }

    res.push_back({L,R});
}



// ll m;
// vector<ll> expd(100); 
// void cal(){
    
//     expd[0] = 10;
//     for (ll i = 1;i<100;i++){
//         expd[i] = (expd[i-1]*expd[i-1])%m;
//     }
// }

// ll exp10mod(ll exp){
//     ll c = exp;
//     ll ret = 1;
//     ll cur = 0;
//     while(c){
//         if(c&1)ret*=expd[cur];
//         c/=2;
//         ret%=m;
//         cur++;
//     }
//     return ret;
// }

// ll m;
// ll A;
// vector<i128> expd(100); 
// void cal(){
    
//     expd[0] = A%m;
//     for (ll i = 1;i<100;i++){
//         expd[i] = (expd[i-1]*expd[i-1])%m;
//     }
// }

// ll expAmod(ll exp){
//     i128 c = exp;
//     i128 ret = 1;
//     i128 cur = 0;
//     while(c){
//         if(c&1)ret*=expd[cur];
//         c/=2;
//         ret%=m;
//         cur++;
//     }
//     return (ll)ret;
// }

// #define pii pair<int,int>
// #define pll pair<ll,ll>
// #define vecll vector<ll>
// #define vecpll vector<pll>
// #define vecs vector<string>
// #define cinvec(vec,type,size) vector<type> vec(size); for(ll i=0;i<size;i++) cin >> vec[i];


/*セグ木用*/
// sum
ll op_sum(ll a, ll b) {
    return a + b;
}
ll e_sum() {
    return 0LL;
}

//max
ll op_max(ll a, ll b) {
    return max(a, b);
}
ll e_max() {
    return -(1LL<<60); // 十分小さい値
}

//min
ll op_min(ll a, ll b) {
    return min(a, b);
}
ll e_min() {
    return (1LL<<60); // 十分大きい値
}

//pllmax
pair<ll,ll> op_pair_max(pair<ll,ll> a, pair<ll,ll> b){
    return max(a,b);
}
pair<ll,ll> e_pair_max(){
    return {-1LL<<60, -1LL<<60};
}

//pllmin
pair<ll,ll> op_pair_min(pair<ll,ll> a, pair<ll,ll> b){
    return min(a,b);
}
pair<ll,ll> e_pair_min(){
    return {1LL<<60, 1LL<<60};
}

typedef segtree<ll, op_max, e_max> sgmaxll ;
typedef segtree<ll, op_min, e_min> sgminll ;
typedef segtree<ll, op_sum, e_sum> sgsumll ;
typedef segtree<pair<ll,ll>, op_pair_max, e_pair_max> sgmaxpll ;
typedef segtree<pair<ll,ll>, op_pair_min, e_pair_min> sgminpll ;

//ワーシャルフロイド(参照渡し)
void warshall_floyd(vector<vector<ll>>& c){
    ll N = c.size();
    rep(k,N){
        rep(i,N){
            rep(j,N){
                c[i][j] = min(c[i][j],c[i][k]+c[k][j]);
            }
        }
    }
}

long long iphi(long long r){
    __int128 x = (__int128)5 * r * r;
    long long s = sqrtl((long double)x); // 初期値
    while((__int128)(s+1)*(s+1) <= x) s++;
    while((__int128)s*s > x) s--;
    return (r + s) / 2;
}



// 重複対応のため pair を使う
template<class T>
using SortedMultiset = tree<
    pair<T,int>,
    null_type,
    less<pair<T,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

template<class T>
using RSortedMultiset = tree<
    pair<T,int>,
    null_type,
    greater<pair<T,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

template<class T>
using SortedSet = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;


unsigned long long isqrt_aux(int c,unsigned long long n){
    if (c == 0){
        return 1;
    } else {
        int k = (c - 1) / 2;
        unsigned long long a = isqrt_aux(c / 2, n >> (2*k + 2));
        return (a << k) + (n >> (k+2)) / a;
    }
}

unsigned long isqrt(unsigned long long n){
    if (n == 0){
        return 0;
    } else {
        unsigned long long a = isqrt_aux(( 63 - __builtin_clzll(n)) / 2, n);
        return n <= a * a - 1 ? a - 1 : a;
    }
}



struct SegTreeMAX {
    int n;
    vector<long long> seg;
    const long long INF = (1LL << 60);

    SegTreeMAX(int N) {
        n = 1;
        while (n < N) n <<= 1;
        seg.assign(2 * n, -INF);
    }

    // a[pos] = val
    void update(int pos, long long val) {
        pos += n;
        seg[pos] = val;
        while (pos > 1) {
            pos >>= 1;
            seg[pos] = max(seg[pos << 1] , seg[pos << 1 | 1]);
        }
    }

    // [l, r) の区間和
    long long query(int l, int r) {
        long long res = -INF;
        l += n;
        r += n;
        while (l < r) {
            if (l & 1) res = max(seg[l++],res);
            if (r & 1) res = max(seg[--r],res);
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
};



struct SegTreeMIN {
    int n;
    vector<long long> seg;
    const long long INF = (1LL << 60);

    SegTreeMIN(int N) {
        n = 1;
        while (n < N) n <<= 1;
        seg.assign(2 * n, INF);
    }

    // a[pos] = val
    void update(int pos, long long val) {
        pos += n;
        seg[pos] = val;
        while (pos > 1) {
            pos >>= 1;
            seg[pos] = min(seg[pos << 1], seg[pos << 1 | 1]);
        }
    }

    // [l, r) の区間min
    long long query(int l, int r) {
        long long res = INF;
        l += n;
        r += n;
        while (l < r) {
            if (l & 1) res = min(res, seg[l++]);
            if (r & 1) res = min(res, seg[--r]);
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
};

// 1点更新・区間和 セグメント木
struct SegTreeSUM {
    int n;
    vector<long long> seg;

    SegTreeSUM(int N) {
        n = 1;
        while (n < N) n <<= 1;
        seg.assign(2 * n, 0);
    }

    // a[pos] = val
    void update(int pos, long long val) {
        pos += n;
        seg[pos] = val;
        while (pos > 1) {
            pos >>= 1;
            seg[pos] = seg[pos << 1] + seg[pos << 1 | 1];
        }
    }

    // [l, r) の区間和
    long long query(int l, int r) {
        long long res = 0;
        l += n;
        r += n;
        while (l < r) {
            if (l & 1) res += seg[l++];
            if (r & 1) res += seg[--r];
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
};


std::ostream &operator<<(std::ostream &dest, __int128_t value) {
  std::ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = std::end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = std::end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(std::ios_base::badbit);
    }
  }
  return dest;
}

template <typename T, typename F>
struct SegmentTree2D {
 private:
  int id(int h, int w) const { return h * 2 * W + w; }

 public:
  int H, W;
  vector<T> seg;
  const F f;
  const T I;

  SegmentTree2D(int h, int w, F _f, const T& i) : f(_f), I(i) { init(h, w); }

  void init(int h, int w) {
    H = W = 1;
    while (H < h) H <<= 1;
    while (W < w) W <<= 1;
    seg.assign(4 * H * W, I);
  }

  // build にのみ呼ぶ
  void set(int h, int w, const T& x) { seg[id(h + H, w + W)] = x; }

  void build() {
    // w in [W, 2W)
    for (int w = W; w < 2 * W; w++) {
      for (int h = H - 1; h; h--) {
        seg[id(h, w)] = f(seg[id(2 * h + 0, w)], seg[id(2 * h + 1, w)]);
      }
    }
    // h in [0, 2H)
    for (int h = 0; h < 2 * H; h++) {
      for (int w = W - 1; w; w--) {
        seg[id(h, w)] = f(seg[id(h, 2 * w + 0)], seg[id(h, 2 * w + 1)]);
      }
    }
  }

  T get(int h, int w) const { return seg[id(h + H, w + W)]; }
  T operator()(int h, int w) const { return seg[id(h + H, w + W)]; }

  void update(int h, int w, const T& x) {
    h += H, w += W;
    seg[id(h, w)] = x;
    for (int i = h >> 1; i; i >>= 1) {
      seg[id(i, w)] = f(seg[id(2 * i + 0, w)], seg[id(2 * i + 1, w)]);
    }
    for (; h; h >>= 1) {
      for (int j = w >> 1; j; j >>= 1) {
        seg[id(h, j)] = f(seg[id(h, 2 * j + 0)], seg[id(h, 2 * j + 1)]);
      }
    }
  }

  T _inner_query(int h, int w1, int w2) {
    T res = I;
    for (; w1 < w2; w1 >>= 1, w2 >>= 1) {
      if (w1 & 1) res = f(res, seg[id(h, w1)]), w1++;
      if (w2 & 1) --w2, res = f(res, seg[id(h, w2)]);
    }
    return res;
  }

  // [ (h1,w1), (h2,w2) ) 半開
  T query(int h1, int w1, int h2, int w2) {
    if (h1 >= h2 || w1 >= w2) return I;
    T res = I;
    h1 += H, h2 += H, w1 += W, w2 += W;
    for (; h1 < h2; h1 >>= 1, h2 >>= 1) {
      if (h1 & 1) res = f(res, _inner_query(h1, w1, w2)), h1++;
      if (h2 & 1) --h2, res = f(res, _inner_query(h2, w1, w2));
    }
    return res;
  }
};

// using mint = modint1000000007;

struct Comb {
    vector<mint> fact, finv;

    Comb(int n) {
        fact.resize(n + 1);
        finv.resize(n + 1);

        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
        }

        finv[n] = fact[n].inv();
        for (int i = n; i >= 1; i--) {
            finv[i - 1] = finv[i] * i;
        }
    }

    mint C(long long n, long long k) {
        if (n < 0 || k < 0 || n < k) return 0;
        return fact[n] * finv[k] * finv[n - k];
    }
};

// int main() {
//     Comb comb(1000000);

//     cout << comb.C(5, 2).val() << endl; // 10
// }


struct BigNComb {
    vector<mint> inv;

    BigNComb(int kmax) {
        inv.resize(kmax + 1);

        for (int i = 1; i <= kmax; i++) {
            inv[i] = mint(i).inv();
        }
    }

    mint C(long long n, long long k) {
        if (n < 0 || k < 0 || n < k) return 0;

        mint res = 1;

        for (long long i = 0; i < k; i++) {
            res *= mint(n - i);
            res *= inv[i + 1];
        }

        return res;
    }
};


// int main() {
//     BigNComb comb(1000000);

//     cout << comb.C((long long)1e18, 3).val() << endl;
// }

// 上限 z で打ち切るべき乗計算 (x^y)
// ll power_capped(ll x, ll y, ll z) {
//     if (x == 0) return (y == 0) ? 1 : 0;
//     if (x == 1) return min(1LL, z);
    
//     ll res = 1;
//     for (ll i = 0; i < y; ++i) {
//         // res * x >= z となるか判定（オーバーフロー防止のため割り算でチェック）
//         if (z / x < res) return z;
//         res *= x;
//     }
//     return res;
// }

// // tet(x, y) が z 未満ならその値を、z 以上なら z を返す関数
// ll tet_capped(ll x, ll y, ll z) {
//     if (x == 0) return (y % 2 == 0) ? min(1LL, z) : 0;
//     if (x == 1) return min(1LL, z);
//     if (y == 0) return min(1LL, z);
//     if (y == 1) return min(x, z);
//     if (y == 2) return power_capped(x, x, z);
//     if (y == 3) {
//         ll exp = power_capped(x, x, z);
//         if (exp >= z) return z;
//         return power_capped(x, exp, z);
//     }
    
//     // y >= 4 の場合
//     if (x == 2 && y == 4) return min(65536LL, z);
    
//     // これ以外のケース (x>=2 かつ y>=5、または x>=3 かつ y>=4) は
//     // 確実に 10^18 などを超えるため、無条件で z を返す
//     return z;
// }

ll modpow(ll a,ll b ,int m){
    ll ans = 1;
    a %= m;

    while(true){
        if(b == 0){
            break;
        }else{
            if(b%2 == 1){
                ans *= a;
                ans %= m;
            }
            a *= a;
            a %= m;
        }
        b/=2;
    }
    return ans;
}

// ll totient(ll n){
//     long long result = n;
//     for (long long i = 2; i * i <= n; ++i) {
//         if (n % i == 0) {
//             while (n % i == 0) {
//                 n /= i;
//             }
//             result -= result / i;
//         }
//     }
//     if (n > 1) {
//         result -= result / n;
//     }
//     return result;
// }

// vector<ll> totients;
// void InitModTet(ll m){
//     totients.clear();
//     ll m_ = m;
//     while(true){
//         if(m_ != 1){
//             totients.append(m_);
//             m_ = totient(m_);
//         }else{
//             totients.append(m_);
//             break;
//         }
//     }
// }


// ll modTet(ll a,ll b,ll lv){
//     ll m = totients[lv];
//     if (m == 1){
//         return 0;
//     }
//     if (b == 1){
//         return 1 % m;
//     }
//     ll nxm = totients[lv+1];
//     ll cpv = tet_capped(a,b-1,nxm);
//     ll expo;
//     if(cpv < nxm){
//         expo = cpv;
//     }else{
//         expo = modTet(a,b-1,lv + 1)+nxm;
//     }
//     return modpow(a,expo,m);
// }

// ll modack;
// void InitModAckermann(ll m){
//     InitModTet(m);
//     modack = m;
// }

// ll modAckermann(ll m,ll n){
//     if(m >= 1 && n == 0){
//         m--;
//         n = 1;
//     }

//     if (m == 0){
//         return (n + 1) % modack;
//     }else if(m == 1){
//         return (n + 2) % modack;
//     }else if(m == 2){
//         return (2* n + 3) % modack;
//     }else if(m == 3){
//         return (modpow(2,n+3,modack)-3+modack)%modack;
//     }else if(m == 4){
//         return (modTet(2,n+3,0)-3+modack)%modack;
//     }else if(m == 5 && n == 1){
//         return (modTet(2,65536,0)-3+modack)%modack;
//     }else{
//         return (modTet(2,INFLL,0)-3+modack)%modack;
//     }
// }


// // int main(){
// //     ll m = expo(14,8);
// //     InitModAckermann(m);
// //     // rep(i,totients.size()){
// //     //     cout << totients[i] << " ";
// //     // }
// //     // cout << endl;
// //     // cout << modTet(17,5,0) << endl;
// //     // cout << modAckermann(4,3) << endl;
// //     ll ans = 0;
// //     rep(i,7){
// //         cout << modAckermann(i,i) << endl;
// //         ans += modAckermann(i,i);
// //         ans %=m;
// //     }
// //     print(ans);
// // }
struct KDTree {
    struct Point {
        int x, y, id;
    };

    struct Node {
        int x, y;
        int x_min, x_max, y_min, y_max;
        int left, right;
    };

    vector<Point> points;
    vector<Node> tree;
    int root;

    KDTree() : root(-1) {}

    KDTree(const vector<Point>& pts) {
        init(pts);
    }

    void init(const vector<Point>& pts) {
        points = pts;
        tree.clear();
        tree.reserve(points.size()); 
        root = build(0, points.size(), 0);
    }

    // クエリ: qx1 < x < qx2 かつ qy1 < y < qy2 (境界を含まない)
    bool query(int qx1, int qx2, int qy1, int qy2) const {
        return has_point_in_range(root, qx1, qx2, qy1, qy2);
    }

private:
    void update_bbox(int u) {
        tree[u].x_min = tree[u].x_max = tree[u].x;
        tree[u].y_min = tree[u].y_max = tree[u].y;
        
        for (int child : {tree[u].left, tree[u].right}) {
            if (child != -1) {
                tree[u].x_min = min(tree[u].x_min, tree[child].x_min);
                tree[u].x_max = max(tree[u].x_max, tree[child].x_max);
                tree[u].y_min = min(tree[u].y_min, tree[child].y_min);
                tree[u].y_max = max(tree[u].y_max, tree[child].y_max);
            }
        }
    }

    int build(int l, int r, int depth) {
        if (l >= r) return -1;
        int mid = l + (r - l) / 2;

        if (depth % 2 == 0) {
            nth_element(points.begin() + l, points.begin() + mid, points.begin() + r,
                        [](const Point& a, const Point& b) { return a.x < b.x; });
        } else {
            nth_element(points.begin() + l, points.begin() + mid, points.begin() + r,
                        [](const Point& a, const Point& b) { return a.y < b.y; });
        }

        int u = tree.size();
        tree.push_back({points[mid].x, points[mid].y, 0, 0, 0, 0, -1, -1});

        tree[u].left = build(l, mid, depth + 1);
        tree[u].right = build(mid + 1, r, depth + 1);
        
        update_bbox(u);
        return u;
    }

    bool has_point_in_range(int u, int qx1, int qx2, int qy1, int qy2) const {
        if (u == -1) return false;

        // 1. 交差しない場合は枝刈り (境界上は範囲外なので <= に変更)
        if (tree[u].x_max <= qx1 || tree[u].x_min >= qx2 || 
            tree[u].y_max <= qy1 || tree[u].y_min >= qy2) {
            return false;
        }

        // 2. 完全に包含されている場合は即座にtrue (境界を含まないので < に変更)
        if (qx1 < tree[u].x_min && tree[u].x_max < qx2 && 
            qy1 < tree[u].y_min && tree[u].y_max < qy2) {
            return true;
        }

        // 3. 現在のノード自身が範囲内かチェック (境界を含まないので < に変更)
        if (qx1 < tree[u].x && tree[u].x < qx2 && 
            qy1 < tree[u].y && tree[u].y < qy2) {
            return true;
        }

        // 4. 左右の部分木を探索
        if (has_point_in_range(tree[u].left, qx1, qx2, qy1, qy2)) return true;
        if (has_point_in_range(tree[u].right, qx1, qx2, qy1, qy2)) return true;

        return false;
    }
};

char rcpwin(char a){
    if(a == 'g'){
        return 'p';
    }else if(a == 'c'){
        return 'g';
    }else{
        return 'c';
    }
}


vector<ll> divisor(ll n) {
  vector<ll> ret;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ret.push_back(i);
      if (i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return ret;
}


/*
ここから下がsolve
*/


// ll threes(string N){
//     int dp[502][2][2];
//     //ベクターnを構成
//     vector<int> n;
//     for(auto a : N){
//         n.push_back(a-'0');
//     }
//     int l = N.size();  //nの長さ

//     dp[0][0][0] = 1;  //初期条件。他は0で初期化されている
//     for(int i = 0; i < l; i++){
//         for(int smaller = 0; smaller < 2; smaller++){
//         for(int j = 0; j < 2; j++){
//             for(int x = 0; x <= (smaller ? 9 : n[i]); x++){
//                 dp[i + 1][smaller || x < n[i]][j || x == 3] += dp[i][smaller][j];
//                 dp[i + 1][smaller || x < n[i]][j || x == 3] %= 998244353 ;
//             }
//         }
//         }
//     }
//     return  (dp[l][0][1] + dp[l][1][1])% 998244353 ;
// }

// ll threek(string N){

// }

// int main(){
//     string S;
//     cin >> S;
//     rep(i,S.size()){
//         print((int)S[i]);
//     }
// }
template< unsigned mod >
struct RollingHash {
  vector< unsigned > hashed, power;

  inline unsigned mul(unsigned a, unsigned b) const {
    unsigned long long x = (unsigned long long) a * b;
    unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;
    asm("divl %4; \n\t" : "=a" (d), "=d" (m) : "d" (xh), "a" (xl), "r" (mod));
    return m;
  }

  RollingHash(const string &s, unsigned base = 10007) {
    int sz = (int) s.size();
    hashed.assign(sz + 1, 0);
    power.assign(sz + 1, 0);
    power[0] = 1;
    for(int i = 0; i < sz; i++) {
      power[i + 1] = mul(power[i], base);
      hashed[i + 1] = mul(hashed[i], base) + s[i];
      if(hashed[i + 1] >= mod) hashed[i + 1] -= mod;
    }
  }

  unsigned get(int l, int r) const {
    unsigned ret = hashed[r] + mod - mul(hashed[l], power[r - l]);
    if(ret >= mod) ret -= mod;
    return ret;
  }

  unsigned connect(unsigned h1, int h2, int h2len) const {
    unsigned ret = mul(h1, power[h2len]) + h2;
    if(ret >= mod) ret -= mod;
    return ret;
  }

  int LCP(const RollingHash< mod > &b, int l1, int r1, int l2, int r2) {
    int len = min(r1 - l1, r2 - l2);
    int low = -1, high = len + 1;
    while(high - low > 1) {
      int mid = (low + high) / 2;
      if(get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;
      else high = mid;
    }
    return (low);
  }
};

using RH1 = RollingHash< 1000000007 >;
using RH2 = RollingHash<998244353 >;


triplet maxSubarraySum(vector<ll> &arr) {
    
    // Stores the result (maximum sum found so far)
    ll res = arr[0];           
    
    // Maximum sum of subarray ending at current position
    ll maxEnding = arr[0];     
    ll l,r,resl,resr;

    for (int i = 1; i < arr.size(); i++) {
        
        // Either extend the previous subarray or start 
        // new from current element
        maxEnding = max(arr[i], maxEnding + arr[i]);

        if(maxEnding == arr[i]){
            l = i;
            r = i;
        }else {
            r = i;
        }

        // Update result if the new subarray sum is larger
        if(chmax(res, maxEnding)){
            resl = l;
            resr = r;
        }
    }

    return {res,resl,resr};
}

// int main() {
//     vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
//     cout << maxSubarraySum(arr); 
//     return 0;
// }

// 入力


// int main(){
//     ll N,K;
//     cin >> N >> K;
//     vector<ll> W(N),P(N);
//     rep(i,N){
//         cin >> W[i] >> P[i];
//     }
//     vector<vector<pll>> dp(N+1,vector<pll>(N+1,{-1,0}));
    
//     dp[0][0] = {0,0};
//     rep(i,N){
//         rep(j,N){
//     rep(I,N+1){
//         rep(J,N+1){
//             cout << dp[I][J].second << "/" << dp[I][J].first <<" ";
//         }
//         cout << endl;
//     }
//             {
//                 if(dp[i][j].first == -1){continue;}
//                 // if(dp[i][j].first == 0){
//                 //     dp[i+1][j+1] = {W[i]*100,P[i]*W[i]};
//                 // }
//                 {
//                     //use
//                     double old = dp[i][j+1].second/(double)dp[i][j+1].first;
//                     double neww = (dp[i][j].second+P[i]*W[i])/(double)(dp[i][j].first+W[i]*100);
//                     // print(neww);
//                     cout << i << " " << j << " " << neww << " " << old << endl;
//                     if(neww>old){
//                         cout << "updated" << endl;
//                         dp[i+1][j+1] = {dp[i][j].first+W[i]*100,dp[i][j].second+P[i]*W[i]};
//                     }else{
//                         dp[i+1][j+1] = {dp[i][j+1].first,dp[i][j+1].second};
//                     }
//                 }

//                 {
//                     //no use
//                     double old = dp[i+1][j].second/(double)dp[i+1][j].first;
//                     double neww = (dp[i][j].second)/(double)(dp[i][j].first);
//                     // print(neww);
//                     cout << i << " " << j << " " << neww << " " << old << endl;
//                     if(neww<old){
//                         cout << "updated" << endl;
                        
//                         dp[i+1][j] = {dp[i+1][j].first,dp[i+1][j].second};
//                     }else{
//                         dp[i+1][j] = {dp[i][j].first,dp[i][j].second};
//                     }
//                 }
//                 // dp[i+1][j] = {dp[i][j].first,dp[i][j].second};
//             }
//         }
//     }

//     rep(i,N+1){
//         rep(j,N+1){
//             cout << dp[i][j].second << "/" << dp[i][j].first <<" ";
//         }
//         cout << endl;
//     }
//     println_decimal(dp[N][K].second/(double)dp[N][K].first*100,17);
// }



/// @brief 最長増加部分列（LIS）のインデックスを返します
/// @tparam Strict 狭義単調増加の場合 true, 広義単調増加の場合 false
/// @tparam Type 数列の要素の型
/// @param v 数列
/// @return 最長増加部分列（LIS）のインデックス
/// @note 1.4 最長増加部分列の復元
/// @see https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/lis
template <bool Strict>
std::vector<int> LIS(const std::vector<int >& v)
{
	std::vector<int> dp;

	auto it = dp.begin();

	std::vector<int> positions;

	for (const auto& elem : v)
	{
		if constexpr (Strict)
		{
			it = std::lower_bound(dp.begin(), dp.end(), elem);
		}
		else
		{
			it = std::upper_bound(dp.begin(), dp.end(), elem);
		}

		positions.push_back(static_cast<int>(it - dp.begin()));

		if (it == dp.end())
		{
			dp.push_back(elem);
		}
		else
		{
			*it = elem;
		}
	}

	std::vector<int> subseq(dp.size());

	int si = static_cast<int>(subseq.size()) - 1;

	int pi = static_cast<int>(positions.size()) - 1;

	while ((0 <= si) && (0 <= pi))
	{
		if (positions[pi] == si)
		{
			subseq[si] = pi;

			--si;
		}

		--pi;
	}

	return subseq;
}

// int main()
// {
// 	int N;
// 	std::cin >> N;

// 	std::vector<int> A(N);
// 	for (auto& a : A)
// 	{
// 		//std::cin >> a;
// 	}

// 	std::cout << LIS<true>(A).size() << '\n';
// }

bool isSubSequence(string S, string T){
    ll i = 0;
    for(auto t:T){
        while(i<S.size() && S[i] != t){
            i++;
        }
        if(i==S.size()){
            return false;
        }
        i++;
    }
    return true;

}

ll binom(ll n,ll r){
    ll ans = 1;
    rep1(i,r){
        ans *= n-i+1;
        ans /= i;
    }
    return ans;
}
// using mint = modint998244353;





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
//   foreach_comb(10, 6, [&](int *indexes) {
//     std::cout << indexes[0] << ',' << indexes[1] << ',' << indexes[2] << std::endl;
//   });
// }

vector<vector<int>> multi_source_bfs(int H, int W, const vector<string> &grid, const vector<pair<int,int>> &starts) {
    // dist配列を初期化(-1で未訪問を表す)
    vector<vector<int>> dist(H, vector<int>(W, -1));

    // 多視点BFS用のキュー
    queue<pair<int,int>> que;

    // 全ての始点をキューに投入し、距離0で初期化
    for (auto &st : starts) {
        dist[st.first][st.second] = 0;
        que.push(st);
    }

    // 方向ベクトル（上下左右）
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    // BFSループ開始
    while (!que.empty()) {
        auto [x, y] = que.front();
        que.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            // 範囲チェック
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;

            // 壁マス('#')は通れないのでスキップ
            if (grid[nx][ny] == '#') continue;

            // すでに訪問済みならスキップ
            if (dist[nx][ny] != -1) continue;

            // 未訪問で通れるマスなら距離を更新
            dist[nx][ny] = dist[x][y] + 1;
            que.push({nx, ny});
        }
    }

    return dist;
}

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     // 入力受け取り
//     int H, W;
//     cin >> H >> W;
//     vector<string> grid(H);
//     for (int i = 0; i < H; i++) {
//         cin >> grid[i];
//     }

//     // 複数の始点を探し、ベクターに格納
//     vector<pair<int,int>> starts;
//     // ここでは 'S' と書かれたマスを始点とみなす
//     for (int i = 0; i < H; i++) {
//         for (int j = 0; j < W; j++) {
//             if (grid[i][j] == 'S') {
//                 starts.push_back({i,j});
//             }
//         }
//     }

//     // 多視点BFS実行
//     vector<vector<int>> dist = multi_source_bfs(H, W, grid, starts);

//     // 結果出力（各マスの距離を空白区切りで表示）
//     // 到達不能なマスは -1 のまま
//     for (int i = 0; i < H; i++) {
//         for (int j = 0; j < W; j++) {
//             cout << dist[i][j] << (j == W - 1 ? '\n' : ' ');
//         }
//     }

//     return 0;
// }
// int main() {
//     SortedMultiset<int> s;
//     int id = 0;

//     // insert
//     s.insert({5, id++});
//     s.insert({3, id++});
//     s.insert({5, id++});

//     // k番目 (0-indexed)
//     auto it = s.find_by_order(1);
//     cout << it->first << endl;

//     // x未満の個数
//     cout << s.order_of_key({5, 0}) << endl;

//     // erase (1個だけ消す)
//     auto it2 = s.lower_bound({5, 0});
//     if (it2 != s.end()) s.erase(it2);
// }
// 

// void merge_intervals(vector<pair<ll,ll>>& seg,
//                      vector<pair<ll,ll>>& res){
//     if(seg.empty()) return;

//     sort(seg.begin(), seg.end());

//     ll L = seg[0].first;
//     ll R = seg[0].second;

//     for(int i = 1; i < seg.size(); i++){
//         if(seg[i].first > R){
//             res.push_back({L,R});
//             L = seg[i].first;
//             R = seg[i].second;
//         }else{
//             R = max(R, seg[i].second);
//         }
//     }

//     res.push_back({L,R});
// }


int main(){
    //(=^・^=)←猫(笑)
    ll T;
    cin >> T;
    rep(h,T){
        ll a,b,c;
        cin >> a >> b >> c;
        vector<ll> ansA(a);
        vector<ll> ansB(b);
        rep(i,a){
            ansA[i] = i;
        }
        rep(i,b){
            ansB[i] = i;
        }
        set<ll> seen;
        rep(i,a){
            rep(j,b){
                seen.insert(a ^ b);
            }
        }

        for(int x:seen){
            print(x);
        }
    }
 
}
/*
・クエリはソートできないか
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
