#include <algorithm>
#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    const int MOD = 998244353;
    std::vector<long long> power(62, 1);
    for (int i = 1; i < 62; i++) power[i] = power[i - 1] * 2;
    auto nonFinal = [&](auto &&self, long long x) -> long long {
        if (x <= 0) return 0;
        if (x < 2) return 4;
        int a = 2;
        while (power[a + 1] - 2 <= x) a++;
        long long low = power[a] - 2, high = power[a + 1] - 2;
        return std::min(a + 1 + self(self, x - low), a + 2 + high - x);
    };
    auto solve = [&](long long x) -> long long {
        if (x == 0) return 0;
        int k = 0;
        while (power[k + 1] <= x) k++;
        long long ans = x + 100;
        for (int a = std::max(k, 1); a <= k + 1; a++) {
            long long value = power[a] - 1;
            if (value >= x) ans = std::min(ans, a + value - x);
            else ans = std::min(ans, a + nonFinal(nonFinal, x - value));
        }
        return ans;
    };
    int T; std::cin >> T;
    while (T--) {
        long long L, R; std::cin >> L >> R;
        long long ans = 0;
        for (long long x = L; x <= R; x++) ans = (ans + solve(x)) % MOD;
        std::cout << ans << '\n';
    }
    return 0;
}
