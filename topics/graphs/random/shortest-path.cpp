#include <iostream>
#include <vector>
#include <queue>
#include <cstdint>
using P = std::pair<int64_t, int>;

struct Dijkstra {
  int n; std::vector<std::vector<std::pair<int, int64_t>>> g;
  std::vector<int64_t> d;
  void init(int n) { g.resize(n ); d.resize(n, 1e18); this->n = n; }
  void add_egde(int u, int v, int64_t w, bool both=false) {
    g[u].push_back({v, w});
    if (both) g[v].push_back({u, w});
  }
  int64_t shortest_path(int s, int t) {
    d[s] = 0;
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
      auto [d_v, v] = pq.top();
      pq.pop();
      if (d_v != d[v]) continue;
      for (auto& [to, len] : g[v]) {
        if (d[v] + len < d[to]) {
          d[to] = d[v] + len;
          pq.push({d[to], to});
        }
      }
    }

    if (d[t] == 1e18) return -1;
    return d[t];
  };

  void clear() {
    d.resize(n, 1e18);
  }
};


int main() {

  return 0;
}
