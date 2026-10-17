//Compile Options
# pragma GCC target("avx2")
# pragma GCC optimize("O3")
# pragma GCC optimize("unroll-loops")

//libraries
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

//templates

// ---------- 基本 ----------
#define ll long long
#define ull unsigned long long
#define ld long double

#define pii pair<int,int>
#define pll pair<ll,ll>
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
#define print(a) cout << (a) << endl

// その他
#define append push_back

using Graph = vector<vector<int>>;





template <class T>
void println_decimal(T value, int digits) {
    std::cout << std::fixed << std::setprecision(digits) << value << '\n';
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

//使い方
// CumulativeSum<long long> cs;
// cs.push_back(3);
// cs.push_back(5);
// cs.push_back(2);

// // [0,2] = 3+5+2
// cs.range_sum(0, 2);   // 10

// // [-5,1] → [0,1]
// cs.range_sum(-5, 1);  // 8

// // [2,10] → [2,2]
// cs.range_sum(2, 10);  // 2

// // 完全に外
// cs.range_sum(5, 7);   // 0




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

constexpr std::string ToBaseN(unsigned long long n, const unsigned int base)
{
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
	return s;
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
int main() {
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N){
        cin >> A[i];
    }
    SegTreeMAX sgmx(N);
    SegTreeMIN sgmn(N);
    rep(i,N){
        sgmx.update(i,A[i]);
        sgmn.update(i,A[i]);
    }
    ll ok,ng,mid;
    ll ans = 0;
    rep(i,N){
        //l固定
        //k未満探索
        ok = -1;
        ng = N-i;
        while (ng-ok>1){
            mid = (ok+ng)/2;

            if(sgmx.query(i,i+mid+1)-sgmn.query(i,i+mid+1)<K){
                ok =mid;
            }else{
                ng = mid;
            }
        }
        ll dn = ok;

        ok = -1;
        ng = N-i;
        while (ng-ok>1){
            mid = (ok+ng)/2;

            if(sgmx.query(i,i+mid+1)-sgmn.query(i,i+mid+1)<=K){
                ok =mid;
            }else{
                ng = mid;
            }
        }
        ll up = ok;
        ans += up-dn;
    }
    print(ans);
}

/*
・オーバーフロー注意！！
・浮動小数点の誤差に注意！！(掛け算して比較推奨)
・お前そのmultiset本当に必要？(vector推奨)
*/