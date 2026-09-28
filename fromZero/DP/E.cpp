#include <iostream>
#include <vector>
typedef long long ll;
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n, q; std::cin >> n >> q;
        ll ans = 0, prev = 0;
        for (int i = 1; i <= n; ++i) {
            ll x; std::cin >> x;
            if (x > prev) ans += x - prev;
            prev = x;
        }
        std::cout << ans << '\n';
    }
    return 0;
}