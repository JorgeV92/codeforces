#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    int n, x, s; std::cin >> n >> x >> s;
    std::string u; std::cin >> u;
    x = std::min(x, n);
    std::vector<int> dp(x+1, -1e9);
    dp[0] = 0;
    for (char c : u) {
      std::vector<int> ndp = dp;
      for (int k = 0; k <= x; ++k) {
        if (dp[k] < 0) continue;
        int used_seats = dp[k];
        int free_seats = k*s - used_seats;
        if ((c == 'I' || c == 'A') && k < x) 
            ndp[k+1] = std::max(ndp[k+1], used_seats+1);
        if ((c == 'E' || c == 'A') && free_seats > 0) 
            ndp[k] = std::max(ndp[k],used_seats+1);
      }
      dp = ndp;
    }
    std::cout << *std::max_element(dp.begin(), dp.end()) << '\n'; 
  }
  return 0;
}
