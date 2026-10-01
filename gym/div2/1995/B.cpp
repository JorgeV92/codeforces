#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int64_t n, m; std::cin >> n >> m;
        std::vector<int64_t> a(n); for (auto& x : a) std::cin >> x;
        std::sort(a.begin(), a.end());
        int64_t sum = 0, ans = 0;
        int l = 0;
        for (int r = 0; r < n; ++r) {
            sum += a[r];
            while (l <= r && a[r] - a[l] > 1 || sum > m) {
                sum -= a[l++];
            }
            ans = std::max(ans, sum);
        }
        std::cout << ans << '\n';
    }
    return 0;
}