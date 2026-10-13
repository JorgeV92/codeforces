#include <iostream>
#include <vector>
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n;  std::cin >> n;
        std::vector<i64> a(n); for (auto& x : a) std::cin >> x;
        i64 ans = a[0];
        i64 mx = a[0], mn = a[0];
        for (int k = 1; k < n; ++k) {
            ans = std::max(ans, a[k] + std::max(mx, -mn));
            i64 nmx = a[k] + std::max({0LL, mx, 2 *mx, mn, 2 * mn});
            i64 nmn = a[k] + std::min({0LL, mx, 2 * mx , mn , 2 * mn});
            mx = nmx; mn = nmn;
        }
        std::cout << ans << '\n';
    }

    return 0;
}