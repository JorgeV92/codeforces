#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    vector<vector<int>> g(n);
    vector<int> dp(n), depth(n);
    vector<int64_t> ans(n);
    for (int i = 1; i < n; i++) {
      int p; cin >> p;
      p--;
      g[p].push_back(i);
    }

    auto dfs = [&](auto&& dfs, int v, int f) -> void {
      ans[v] = 0;
      dp[v] = depth[v];
      int m1 = depth[v], m2 = depth[v];
      for (int u : g[v]) {
        if (u != f) {
          depth[u] = depth[v] + 1;
          dfs(dfs,u,v);
          dp[v] = max(dp[v], dp[u]);
          ans[v] += ans[u];
          if (dp[u] >= m1) {
            m2 = m1;
            m1 = dp[u];
          } else if (dp[u] >= m2) {
            m2 = dp[u];
          }
        }
      }
      ans[v] += m2 - depth[v] + 1;
    }; dfs(dfs,0,-1);

    cout << ans[0] << '\n';
  }
  return 0;
}
