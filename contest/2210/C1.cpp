#include <iostream>
#include <vector>
#include <numeric>
#include <cstdint>

int64_t _lcm(int64_t a, int64_t b) {
    return a / std::gcd(a, b) * b;
}

void solve() {
    int n; std::cin >> n;
    std::vector<int64_t> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    std::vector<int> g(n-1);
    for (int i = 0; i < n-1; i++) {
        g[i] = std::gcd(a[i], a[i+1]);
    }
    int ans = 0;
    if (g[0] < a[0]) ans++;
    if (g[n-2] < a[n-1]) ans++;
    for (int i = 1; i < n-1; i++) {
        int64_t l = _lcm(g[i-1], g[i]);
        if (l < a[i]) {
            ans++;
        }
    }
    std::cout << ans <<'\n'; 
}

int main() {    
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int T; std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;   
} 