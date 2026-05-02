#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

int main() {        
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    auto jorgee = [&]() -> void {
        std::vector<int> dp(100+2, 1<<30);
        dp[0] = 0;
        for (int c : {1, 3, 6, 10, 15}) {
            for (int x = c; x <= 101; x++) {
                dp[x] = std::min(dp[x], dp[x - c] + 1);
            }
        }
        int T; std::cin >> T;
        while (T--) {
            int64_t n; std::cin >> n;
            int64_t ans = 0;
            if (n > 101) {
                ans = (n - 101 + 14) / 15;
                n -= ans * 15;
            }
            ans += dp[n];
            std::cout << ans << '\n';
        }
    }; jorgee();
    return 0;       
}