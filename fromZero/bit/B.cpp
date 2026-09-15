#include <iostream>
#include <vector>
#include <unordered_map>
using ll = long long;
template<typename T> struct BIT {
    int N; std::vector<T> data;
    void init(int _N) { N = _N; data.resize(N); }
    void add(int p, int x) { for (++p; p<=N; p+=p&-p) data[p-1] += x; }
    T sum(int r) {T s=0; for(;r;r-=r&-r) s+=data[r-1]; return s; }
};

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int> a(n); for (int& x : a) std::cin >> x;
    std::vector<int> L(n), R(n);
    std::unordered_map<int,int> freq;
    for (int i = 0; i < n; ++i) {
        L[i] = ++freq[a[i]];
    }
    freq.clear();
    for (int i = n-1; i >= 0; i--) {
        R[i] = ++freq[a[i]];
    }

    BIT<ll> bit; bit.init(n+1);
    for (int i = 0; i < n; ++i) 
        bit.add(R[i], 1);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        bit.add(R[i], -1);
        ans += bit.sum(L[i]);
    } 
    std::cout << ans << '\n';
    return 0;
}