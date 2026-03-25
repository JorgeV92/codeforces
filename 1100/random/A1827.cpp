#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
using namespace std;

template<unsigned int N> class Field {
    typedef unsigned int ui;
    typedef unsigned long long ull;
    inline ui pow(ui a, ui p) {ui r = 1, e = a;while (p) {if (p&1) {r = ((ull)r * e) % N;}e = ((ull)e*e) % N;p >>= 1;}return r;}
    inline ui inv(ui a) { return pow(a, N-2); }
public:
    inline Field(int x= 0) : v(x) {}
    inline Field<N>& operator+=(const Field<N>& o) {if (v+o.v >= N) v += o.v - N; else v += o.v; return *this; }
    inline Field<N>& operator*=(const Field<N>& o) { v = (ull)v*o.v % N; return *this; }
    inline Field<N>& operator/=(const Field<N>& o) {return *this *= inv(o.v); }
    inline Field<N>& operator-=(const Field<N>& o) {if (v < o.v) v -= o.v-N; else v -= o.v; return *this;}
    inline Field<N> operator*(const Field<N>& o) const {Field<N>r{*this}; return r *= o;}
    inline Field<N> operator/(const Field<N>& o) const {Field<N>r{*this}; return r /= o;}
    inline Field<N> operator+(const Field<N>& o) const {Field<N>r{*this}; return r += o;}
    inline explicit operator ui() const { return v; }
    inline static vector<Field<N>> fact(int t) {
        vector<Field<N>> F(t+1, 1);
        for (int i = 2; i <= t; ++i) {
            F[i] = F[i-1] * i;
        }
        return F;
    }
    inline static vector<Field<N>> invfact(int t) {
        vector<Field<N>> F(t+1, 1);
        Field<N> X{1};
        for (int i = 2; i <= t; i++) {
            X = X*i;
        }
        F[t] =  1 / X;
        for (int i = t-1; i >= 2; --i) {
            F[i] = F[i+1] * (i+1);
        }
        return F;
    }
private:
    ui v;
};
template<unsigned int N> Field<N> operator*(int i, const Field<N>& f) {return Field<N>(i)*f;}
template<unsigned int N> Field<N> operator/(int i, const Field<N>& f) {return Field<N>(i)/f;}
template<unsigned int N>ostream& operator<<(std::ostream& os, const Field<N>& f) {return os<<(unsigned int)f; } 


typedef Field<int(1E9 + 7)> FF;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        FF ans = 1;
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && a[i] > b[j]) {
                j++;
            }
            ans *= j - i;
        }
        cout << ans << '\n';
    }
}