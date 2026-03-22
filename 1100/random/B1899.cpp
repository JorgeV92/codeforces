#include <iostream>
#include <vector>
#include <cstdint>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int64_t> a(n);
    std::vector<int64_t> pref(n+1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        pref[i+1] = pref[i] + a[i];
    }

    int64_t ans = 0;
    for (int k = 1; k <= n; k++) {
        if (n % k == 0) {
            int64_t mn = pref[n], mx = 0;
            for (int i = 0; i < n; i+= k) {
                int64_t v = pref[i+k] - pref[i];
                mn = std::min(mn, v);
                mx = std::max(mx, v);
            }
            ans = std::max(ans, mx- mn);
        }
    }
    std::cout << ans << '\n';
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