#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdint>
const int MAXN = 200000;
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    std::vector<std::vector<int>> primes(MAXN+1);
    for (int p = 2; p <= MAXN; p++) {
        if (primes[p].empty()) {
            for (int x= p; x <= MAXN; x += p) {
                primes[x].push_back(p);
            }
        }
    }
    int T; std::cin>> T;
    while (T--) {
        int n, k; std::cin >> n >> k;
        std::vector<int> a(n); for (int& x : a) std::cin >> x;
        std::vector<int64_t> dp(n+1); // dp[x] = min opterations to make x <= k
        for (int x = k+1; x <= n; ++x) {
            dp[x] = LLONG_MAX;
            for (int p : primes[x]) {
                dp[x] = std::min(dp[x], 1LL + 1LL*p*dp[x/p]);
            }
        }
        int64_t ans = 0;
        for (int x : a) { ans += dp[x]; }
        std::cout << ans << '\n';

    }
    return 0;
}