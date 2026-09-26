#include <iostream>
#include <vector>
#include <cstdint>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n, k; std::cin >> n >> k;
        std::vector<int64_t> a(n); for (auto& x : a) std::cin >> x;
        int64_t ans = 0; 
        int r = n - k + 1, t = std::min(k-1, r);
        for (int i = 0; i < t; i++) {
            ans += std::max(a[i], a[n-i-1]);
        }
        if (r > k-1) {
            for (int i = k-1; i <= n-k; i++) {
                ans += a[i];
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}