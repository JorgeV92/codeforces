#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    int n; std::cin >> n;
    std::vector<int> A(2*n+1); for (int i = 1; i <= 2*n; ++i) std::cin >> A[i];
    std::vector<int> first(n+1,-1), last(2*n+1,-1);
    for (int i = 1; i <= 2*n; ++i) {
      if (first[A[i]] == -1) first[A[i]] = i;
      else last[i] = first[A[i]];
    }
    std::vector<ll> dp(2*n+1);
    for (int i = 1; i <= 2*n; ++i) {
      dp[i] = dp[i-1] + 1;
      if (last[i] != -1) {
        int l = last[i];
        ll len = i - l + 1LL;
        dp[i] = std::max(dp[i], dp[l-1] + len * len);
      }
    }
    std::cout << dp[2*n] << '\n';
  }
  return 0;
}
