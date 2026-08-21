#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

struct DSU {
  std::vector<int> par, sz;
  DSU(int n) : par(n), sz(n,1) {
    iota(par.begin(), par.end(), 0);
  }

  int find(int x) { 
    while (x != par[x]) {
      par[x] = par[par[x]];
      x = par[x];
    }
    return x;
  } 

  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (sz[x] < sz[y]) std::swap(x, y);
    par[y] = x;
    sz[x] += sz[y];
    return true;
  }
};

struct edge  {
  int u, v;
  int64_t w, cost;
  bool in_mst = false;
};

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n, m; std::cin >> n >> m;
  std::vector<edge> edges(m);
  for (edge& e : edges) {
    std::cin >> e.w;
  }
  for (edge& e : edges) {
    std::cin >> e.cost;
  }
  for (edge& e : edges) {
    std::cin >> e.u >> e.v;
    e.u--; e.v--;
  }
  int64_t S{};
  std::cin >> S;

  std::vector<int> order(m);
  std::iota(order.begin(), order.end(), 0);

  std::sort(order.begin(), order.end(), 
            [&](int i, int j) { 
            return edges[i].w < edges[j].w; });

  DSU dsu(n);
  int64_t mst_w = 0;
  std::vector<int> mst_edges;

  std::vector<std::vector<std::pair<int,int>>> tree(n);

  for (int i : order) {
    auto& e = edges[i];
    if (!dsu.unite(e.u, e.v)) continue;
    e.in_mst = true;
    mst_w += e.w;
    mst_edges.push_back(i);
    
    tree[e.u].push_back({e.v, i});
    tree[e.v].push_back({e.u, i});
  }

  int LOG = 1;
  while ((1<<LOG) <= n) ++LOG;

  std::vector<std::vector<int>> up(LOG, std::vector<int>(n));
  std::vector<std::vector<int>> max_edge(LOG, std::vector<int>(n,-1));

  std::vector<int> depth(n), par(n,-1);
  par[0] = 0;
  std::vector<int> st{0};
  while (!st.empty()) {
    int u = st.back();
    st.pop_back();
    for (auto [v, i] : tree[u]) {
      if (v == par[u]) continue;
      par[v] = u;
      depth[v] = depth[u] + 1;
      up[0][v] = u;
      max_edge[0][v] = i;
      st.push_back(v);
    }
  }

  auto heavier_edge = [&](int i , int j) {
    if (i == -1) return j;
    if (j == -1) return i;
    if (edges[i].w >= edges[j].w) return i;
    return j;
  };

  for (int k = 1; k < LOG; ++k) {
    for (int v = 0; v < n; ++v) {
      int j = up[k-1][v];
      up[k][v] = up[k-1][j];
      max_edge[k][v] = heavier_edge(max_edge[k-1][v], max_edge[k-1][j]);
    }
  }

  auto get_max_edge_on_path = [&](int u, int v) {
    int ans = -1;
    if (depth[u] < depth[v]) std::swap(u, v);
    int d = depth[u]-depth[v];
    for (int k = LOG-1; k >= 0; --k) {
      if (d & (1 << k)) {
        ans = heavier_edge(ans, max_edge[k][u]);
        u = up[k][u];
      }
    }
    if (u == v) return ans;
    for (int k = LOG-1; k >= 0; --k) {
      if (up[k][u] != up[k][v]) {
        ans = heavier_edge(ans, max_edge[k][u]);
        ans = heavier_edge(ans, max_edge[k][v]);
        u = up[k][u], v = up[k][v];
      }
    }
    ans = heavier_edge(ans, max_edge[0][u]);
    ans = heavier_edge(ans, max_edge[0][v]);
    return ans;
  };

  int64_t best = LLONG_MAX;
  int dis_edge = -1;
  int removed = -1;

  for (int i = 0; i < m; ++i) {
    const auto& e = edges[i];
    int64_t re = S / e.cost;
    int64_t cand = mst_w - re;
    int edge_rm = -1;
    if (!e.in_mst) {
      edge_rm = get_max_edge_on_path(e.u, e.v);
      cand += e.w - edges[edge_rm].w;
    }
    if (cand < best) {
      best = cand;
      dis_edge = i;
      removed = edge_rm;
    }
  }

  std::vector<char> used(m,false);
  for (int i : mst_edges) {
    used[i] = true;
  }

  if (removed != -1) {
    used[removed] = false;
    used[dis_edge] = true;
  }

  std::cout << best << '\n';

  for (int i = 0; i  < m; i++) {
    if (!used[i]) continue;
    int64_t fw = edges[i].w;
    if (i == dis_edge) {
      fw -= S / edges[i].cost;;
    }
    std::cout << i + 1 << ' ' << fw << '\n';
  }
  

  return 0;
}
