#include <cmath>
#include <ios>
#include <iostream>
#include <vector>
const int mod = 1e9+7;
int dp[100005], pref[100005];
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T, K; std::cin >> T >> K;
  dp[0] = 1;
  for (int i = 1; i <= 100000; ++i) {
    dp[i] = dp[i-1];
    if (i >= K)
        dp[i] = (dp[i] + dp[i-K]) % mod;
    pref[i] = (pref[i-1] + dp[i]) % mod;
  }
  while (T--) {
    int a, b; std::cin >> a >> b;
    std::cout << (pref[b] - pref[a-1] + mod) % mod << '\n';
  }
  return 0;

}

