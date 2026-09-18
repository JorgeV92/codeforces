#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
template<typename T> struct BIT {
    int N; std::vector<T> data; 
    void init(int _N) { N = _N; data.resize(N); }
    void add(int p, T x) { for(++p; p<= N; p+=p&-p) data[p-1]+=x; }
    T sum(int r) {T s=0; for(;r;r-=r&-r)s+=data[r-1]; return s;}
    T sum(int l, int r) { return sum(r)-sum(l); }
};

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int n, q; std::cin >> n >> q;
    std::vector<int> a(n); for (int& x : a) std::cin >> x;
    BIT<ll> b;
    b.init(n);
    while (q--) {
        int l, r; std::cin >> l >> r;
        --l; --r;
        b.add(l,1);
        if (r + 1 < n) b.add(r+1,-1);
    }
    std::vector<ll> freq(n);
    for (int i = 0; i < n; ++i) freq[i] = b.sum(i+1);
    std::sort(a.begin(), a.end());
    std::sort(freq.begin(), freq.end());
    ll ans = 0;
    for (int i = 0; i < n; ++i) ans += a[i] * freq[i];
    std::cout << ans << '\n';
    return 0;
}