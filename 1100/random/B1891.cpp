#include <iostream>
#include <vector>
#include <cstdint>
#include <array>

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int64_t> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::array<int, 30> f{};
    for (int i = 0; i < 30; i++) {
        f[i] = (1 << i);
    }
    while (q--) {
        int x;
        std::cin >> x;
        for (int i = 0; i < 30; i++) {
            if ((f[i] & (1 << x) - 1) == 0) {
                f[i] += (1 << (x-1));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int k = __builtin_ctz(a[i]);
        a[i] += f[k] - (1 << k);
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
    
}       

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}