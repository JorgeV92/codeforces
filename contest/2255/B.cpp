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

const int MAXN = 1000000;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    auto fact = FF::fact(MAXN);
    auto invfact = FF::invfact(MAXN);

    auto _nCk = [&](int n, int k) -> FF {
        if (k<0 || k > n) return 0;
        return fact[n] * invfact[k] * invfact[n-k];
    };

    int T; std::cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        int zeros = 0;
        for (char c : s) {
            if (c == '0') 
                zeros++;
        }
        int ones = n - zeros;
        int runs = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i] != s[i-1]) runs++;
        }
        int zero_runs = 0;
        int one_runs = 0;
        if (s[0] == '0') {
            zero_runs = (runs+1) / 2;
            one_runs = runs/2;
        } else {
            one_runs = (runs+1) / 2;
            zero_runs = runs/2;
        }

        FF zero_ways = 1;
        FF one_ways = 1;
        
        if (zero_runs > 0) {
            zero_ways = _nCk(zeros-1, zero_runs-1);
        }
        if (one_runs > 0) {
            one_ways = _nCk(ones-1, one_runs-1);
        }

        FF ans = zero_ways * one_ways;
        cout << ans << '\n';
    }
    return 0;
}   