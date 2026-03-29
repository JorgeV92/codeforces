#include <iostream>
#include <vector>

using namespace std;

template <unsigned int N> class Field {
    typedef unsigned int ui;
    typedef unsigned long long ull;
	inline ui pow(ui a, ui p){ui r=1,e=a;while(p){if(p&1){r=((ull)r*e)%N;}e=((ull)e*e)%N;p>>=1;}return r;}
	inline ui inv(ui a){return pow(a,N-2);}
public:
    inline Field(int x = 0) : v(x) {}
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
private: ui v;
};
template<unsigned int N>istream &operator>>(std::istream&is,Field<N>&f){unsigned int v;is>>v;f=v;return is;}
template<unsigned int N>ostream &operator<<(std::ostream&os,const Field<N>&f){return os<<(unsigned int)f;}
template<unsigned int N>Field<N> operator+(int i,const Field<N>&f){return Field<N>(i)+f;}
template<unsigned int N>Field<N> operator-(int i,const Field<N>&f){return Field<N>(i)-f;}
template<unsigned int N>Field<N> operator*(int i,const Field<N>&f){return Field<N>(i)*f;}
template<unsigned int N>Field<N> operator/(int i,const Field<N>&f){return Field<N>(i)/f;}

typedef Field<676767677> FF;

const int MAXF = 2000005; 
vector<FF> F_fact, F_invfact;

void precompute() {
    F_fact = FF::fact(MAXF);
    F_invfact = FF::invfact(MAXF);
}

FF binom(int n, int k) {
    if (k < 0 || k > n || n < 0) return FF(0);
    return F_fact[n] * F_invfact[k] * F_invfact[n - k];
}

int n, m;
FF total_depth = 0;
FF depth_1 = 0;
FF subtracted_sum = 0;

void dfs(int l, int r, int depth) {
    if (l > r) return;
    int mid = (l + r) / 2; 
    total_depth += depth;
    if (mid == 1) {
        depth_1 = depth;
    }
    if (r < n) {
        int M = m - 1;
        FF term1 = binom(M + n - 1, n - 1);
        FF term2 = binom(M + n - r + l - 2, n - r + l - 2);
        subtracted_sum += (term1 - term2);
        if (l == 1) {
            FF term3 = binom(M - 1 + n - r, n - r - 1);
            subtracted_sum += term3;
        }
    }

    dfs(l, mid - 1, depth + 1);
    dfs(mid + 1, r, depth + 1);
}

void solve() {
    cin >> n >> m;
    total_depth = 0;
    depth_1 = 0;
    subtracted_sum = 0;

    dfs(1, n, 1);

    int M = m - 1;
    FF T1 = binom(M + n, n);
    FF T2 = binom(M - 1 + n, n);
    FF first_part = total_depth * T2 + depth_1 * (T1 - T2);
    FF ans = first_part - subtracted_sum;

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    precompute();
    
    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}