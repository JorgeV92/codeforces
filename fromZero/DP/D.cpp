#include <iostream>
#include <array>
#include <string>
#include <algorithm>
#include <cstdint>
const int64_t INF = 1e18;
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::array<int64_t, 8> dp;
    dp.fill(INF);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        int64_t cost; 
        std::string s;
        std::cin >> cost >> s;
        int mm=0;
        for (char c : s) {
            if (c =='A') mm |= 1;
            else if (c == 'B') mm |= 2;
            else mm |= 4;
        }
        std::array<int64_t, 8> ndp = dp;
        for (int mask = 0; mask < 8; mask++) {
            if (dp[mask] == INF) continue;
            int nm = mask | mm;
            ndp[nm] = std::min(ndp[nm], dp[mask] + cost);
        }
        dp = ndp;
    }
    if (dp[7] == INF) std::cout << -1 << '\n';
    else std::cout << dp[7] << '\n';

    return 0;
}