#include <iostream>
#include <vector>
using i64 = long long;
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<i64> H(n+1), P(n+1), S(n+1);
  for (int i = 0; i < n; i++) {
    char c; std::cin >> c;
    P[i+1] = P[i]; H[i+1] = H[i]; S[i+1] = S[i];
    if (c == 'H') H[i+1]++;
    if (c == 'P') P[i+1]++;
    if (c == 'S') S[i+1]++;
  }
  std::vector<i64> win[3] = {S, H , P};
  i64 ans = 0;
  for (int k = 0; k <= n; k++) {
    for (int g = 0; g < 3; g++) {
      for (int h = 0; h < 3; h++) {
        ans = std::max(ans, win[g][k] + win[h][n] - win[h][k]);
      }
    }
  }
  std::cout << ans << '\n';
  return 0;
}
