#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        for (int i = 0 ; i < n; i++) {
            std::cin >> b[i];
        }
        int64_t ans = 0;
        int64_t sum = 0;
        int mx = 0;
        for (int i = 0; i < n && i + 1 <= k; i++) {
            sum += a[i];
            mx = std::max(mx, b[i]);
            ans = std::max(ans, sum + 1LL * mx * (k-i-1));
        }
        std::cout << ans << '\n';
    }
    return 0;
}