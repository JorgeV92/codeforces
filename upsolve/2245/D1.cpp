#include <array>
#include <iostream>
#include <queue>
#include <vector>
#include <ranges>
#include <array>
#include <queue>
namespace rgs = std::ranges;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<std::array<int, 2>>> adj(n);
    std::vector<std::array<int, 2>> deg(n);
    for (int i = 0; i < m; ++i) {
      int o, x, y; std::cin >> o >> x >> y;
      o--; x--; y--;
      deg[x][o]++;
      deg[y][o]++;
      adj[x].push_back({y, o});
      adj[y].push_back({x, o});
    }
    std::vector<int> vis(n);
    std::queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (deg[i][0] == 0 || deg[i][1] == 0) {
        vis[i] = 1;
        q.push(i);
      }
    }
    int cnt = n;
    std::vector<int> ans(n);
    while (!q.empty()) {
      int x= q.front();
      q.pop();
      if (deg[x][0] == 0) {
        ans[x] = -cnt;
      } else {
        ans[x] = cnt;
      }
      cnt--;
      for (auto [y, o] : adj[x]) {
        deg[y][o]--;
        if (!vis[y] && (deg[y][0] == 0 || deg[y][1] == 0)) {
          vis[y] = 1;
          q.push(y);
        }
      }
    }
    if (cnt > 0) {
      std::cout << "NO\n";
    } else {
      std::cout << "YES\n";
      for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << " \n"[i+1==n];
      }
    }
  }
  return 0;
}
