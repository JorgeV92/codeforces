#include <iostream>
#include <vector>
using ll = long long;
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    int n; std::cin >> n;
    std::vector<std::vector<int>> g(n);
    std::vector<ll> dp(n);
    for (int i = 0; i < n-1; ++i) {
      int x, y; std::cin >> x >> y;
      x--; y--;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    ll ans = 0;
    [&](this auto&& self, int v, int f) -> void {
      if (g[v].size() % 2 == 1) {
        dp[v] = 1;
      } 
      for (auto u : g[v]) {
        if (u == f) continue;
        self(u, v);
        ans += ll(dp[v]) * dp[u];
        if (g[v].size() % 2 == 0) {
          dp[v] += dp[u];
        }
      }
    }(0, -1);
  
    std::cout << ans << '\n';
  }
  return 0;
}
