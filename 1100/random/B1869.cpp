#include <iostream>
#include <vector>
#include <cstdint>
int main() {    
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n, k, a, b;
        std::cin >> n >> k >> a >> b;
        a--; b--;
        std::vector<int> x(n), y(n);
        for (int i = 0; i < n; i++) {
            std::cin >> x[i];
            std::cin >> y[i];
        }
        int64_t ans = 1LL * std::abs(x[a] - x[b]) + std::abs(y[a] - y[b]);
        int64_t da = 1E18;
        int64_t db = 1E18;
        for (int i = 0; i < k; i++) {
            da = std::min(da, 1LL *std::abs(x[a]-x[i]) + std::abs(y[a] - y[i]));
            db = std::min(db, 1LL * std::abs(x[b]-x[i]) + std::abs(y[b]-y[i]));
        }
        ans = std::min(ans, da + db);
        std::cout << ans << '\n';
    }
    return 0;       
}