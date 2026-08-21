#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    int N, M; std::cin >> N >> M;
    std::vector<std::vector<int>> g(N);
    for (int i = 0; i < M; ++i) {
      int u, v; std::cin >> u >> v;
      u--; v--;
      g[u].push_back(v);
    }
    std::vector<int> d(N, -1);
    std::queue<std::pair<int,int>> q;
    q.push({0,0});

    while (!q.empty()) {
      auto [u, t] = q.front();
      q.pop();
      if (d[u] != -1) continue;
      d[u] = t;
      for (int v : g[u]) {
        if (d[v] == -1) {
          q.push({v, t+1});
        }
      }
    }

    std::vector<int> order(N);
    std::iota(order.begin(), order.end(), 0);
    std::sort(order.begin(), order.end(), [&](int a, int b) {
      return d[a] > d[b];
    });

    std::vector<int> min_dist = d;
    for (int u : order) {
      for (int v : g[u]) {
        if (d[u] < d[v]) {
          min_dist[u] = std::min(min_dist[u], min_dist[v]);
        } else {
          min_dist[u] = std::min(min_dist[u], d[v]);
        }
      }
    }

    for (int i = 0; i < N; ++i) std::cout << min_dist[i] << ' ';
    std::cout << '\n';

  }
  return 0; 
}
