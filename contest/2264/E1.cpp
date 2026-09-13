#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <unsigned int N> class Field {
    typedef unsigned int ui;
    typedef unsigned long long ull;
	inline ui pow(ui a, ui p){ui r=1,e=a;while(p){if(p&1){r=((ull)r*e)%N;}e=((ull)e*e)%N;p>>=1;}return r;}
	inline ui inv(ui a){return pow(a,N-2);}
public:
    inline Field(int x = 0) : v((x % N + N) % N) {}
	inline Field<N> pow(int p){return (*this)^p; }
	inline Field<N> operator^(int p){return {(int)pow(v,(ui)p)};}

    inline Field<N>&operator+=(const Field<N>&o) {if (v+o.v >= N) v += o.v - N; else v += o.v; return *this; }
    
    inline Field<N>&operator-=(const Field<N>&o) {if (v<o.v) v -= o.v-N; else v-=o.v; return *this; }
    inline Field<N>&operator*=(const Field<N>&o) {v=(ull)v*o.v % N; return *this; }
    inline Field<N>&operator/=(const Field<N>&o) { return *this*=inv(o.v); }
    inline Field<N> operator+(const Field<N>&o) const {Field<N>r{*this};return r+=o;}
    inline Field<N> operator-(const Field<N>&o) const {Field<N>r{*this};return r-=o;}
    inline Field<N> operator*(const Field<N>&o) const {Field<N>r{*this};return r*=o;}
    inline Field<N> operator/(const Field<N>&o) const {Field<N>r{*this};return r/=o;}
    inline Field<N> operator-() {if(v) return {(int)(N-v)}; else return {0};};
    inline Field<N>& operator++() { ++v; if (v==N) v=0; return *this; }
    inline Field<N> operator++(int) { Field<N>r{*this}; ++*this; return r; }
    inline Field<N>& operator--() { --v; if (v==-1) v=N-1; return *this; }
    inline Field<N> operator--(int) { Field<N>r{*this}; --*this; return r; }
    inline bool operator==(const Field<N>&o) const { return o.v==v; }
	inline bool operator!=(const Field<N>&o) const { return o.v!=v; }
	inline explicit operator ui() const { return v; }
	inline static vector<Field<N>>fact(int t){vector<Field<N>>F(t+1,1);for(int i=2;i<=t;++i){F[i]=F[i-1]*i;}return F;}
	inline static vector<Field<N>>invfact(int t){vector<Field<N>>F(t+1,1);Field<N> X{1};for(int i=2;i<=t;++i){X=X*i;}F[t]=1/X;for(int i=t-1;i>=2;--i){F[i]=F[i+1]*(i+1);}return F;}
    inline static Field<N> nCK(int n, int k) { if (k<0||k>n) return 0; auto F = fact(n); auto IF = invfact(n); return F[n] * IF[k] * IF[n-k]; }
private: ui v;
};
template<unsigned int N>istream &operator>>(std::istream&is,Field<N>&f){unsigned int v;is>>v;f=v;return is;}
template<unsigned int N>ostream &operator<<(std::ostream&os,const Field<N>&f){return os<<(unsigned int)f;}
template<unsigned int N>Field<N> operator+(int i,const Field<N>&f){return Field<N>(i)+f;}
template<unsigned int N>Field<N> operator-(int i,const Field<N>&f){return Field<N>(i)-f;}
template<unsigned int N>Field<N> operator*(int i,const Field<N>&f){return Field<N>(i)*f;}
template<unsigned int N>Field<N> operator/(int i,const Field<N>&f){return Field<N>(i)/f;}

typedef Field<998244353> FF;

const int maxn = 3000;

vector<FF> pw2(maxn+1);

void solve() {
    int n; cin >> n;
    vector<int> cnt(n+1);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        cnt[x]++;
    } 
    vector<int> rd(n+1, 1);
    for (int p = 2; p <= n; p++) {
        if (rd[p] == 1) {
            for (int j = p; j <= n; j += p) 
                rd[j] *= p;
        }
    }

    vector<int> nxt(n+1, n+1);
    for (int x= 1; x <= n; ++x) {
        for (int y = x+1; y <= n; y++) {
            if (x%rd[y] == 0) {
                nxt[x] = y;
                break;
            }
        }
    }

     vector<vector<int>> f(n + 1, vector<int>(n + 1));
    for (int x = 1; x <= n; ++x) {
        f[x][x] = x;
    }
    for (int hi = 2; hi <= n; ++hi) {
        for (int lo = 1; lo < hi; ++lo) {
            if (lo % rd[hi] == 0) {
                f[lo][hi] = f[lo - 1][hi - 1];
            } else {
                f[lo][hi] = f[lo][hi - 1];
            }
        }
    }

    vector<int> pref(n+1);
    for (int x = 1; x <= n; ++x) {
        pref[x] = pref[x-1] + cnt[x];
    }
    FF ans=0;
    for (int lo = 1; lo <= n; ++lo) {
        if (cnt[lo] == 0) continue;
        FF C = pw2[cnt[lo]] - FF(1);
        ans += FF(lo) * C;
        for (int hi = lo+1; hi <= n; ++hi) {
            if (cnt[hi] == 0) continue;
            FF C2 = pw2[cnt[hi]] - FF(1);
            int m = pref[hi-1] - pref[lo];
            FF ways = C * C2 * pw2[m];
            ans += FF(f[lo][hi]) * ways;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    pw2[0] = 1;
    for (int i = 1; i <= maxn; ++i) {
        pw2[i] = pw2[i-1] * FF(2);
    }
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;    
}