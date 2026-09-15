#include <iostream>
#include <vector>
using ll = long long;
template<typename T> struct BIT {
    int N; std::vector<T> data; 
    void init(int _N) { N = _N; data.resize(N); }
    void add(int p, T x) { for (++p;p<=N;p+=p&-p) data[p-1]+=x; }
    T sum(int r) { T s=0; for (;r;r-=r&-r) s+=data[r-1]; return s; }
    T sum(int l, int r) { return sum(r) - sum(l); }
};

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int n, m; std::cin >> n >> m;
    std::vector<ll> a(n);
    std::vector<BIT<ll>> bit(m);
    for (auto& b : bit) b.init(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        bit[a[i]%m].add(i, a[i]);
    }
    int q; std::cin >> q;
    while (q--) {
        char t; std::cin >> t;
        if (t == '+') {
            int p; ll x;
            std::cin >> p >> x;
            p--;
            bit[a[p]%m].add(p,-a[p]);
            a[p] += x;
            bit[a[p]%m].add(p, a[p]);
            std::cout << a[p] << '\n';
        } else if (t == '-') {
            int p; ll x;
            std::cin >> p >> x;
            --p;
            if (a[p] >= x) {
                bit[a[p]%m].add(p,-a[p]);
                a[p] -= x;
                bit[a[p]%m].add(p,a[p]);
            }
            std::cout << a[p] << '\n';
        } else {
            int l, r, mod;
            std::cin >> l >> r >> mod;
            std::cout << bit[mod].sum(l-1, r) << '\n';
        }
    }
    return 0;
}