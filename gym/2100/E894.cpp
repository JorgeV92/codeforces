#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;

using ll = long long;
template<typename T> using V = vector<T>;
#define vi V<int>

struct SCC {
  int N; 
  vector<vi> g, rg;
  vi todo, comp, comps;
  vector<bool> vis;
  void init(int _N) {
    N= _N;
    g.resize(N), rg.resize(N), comp.resize(N,-1);
    vis.resize(N);
  }
  void ae(int x, int y) { g[x].push_back(y); rg[y].push_back(x); }
  void dfs(int x) {
    vis[x] = 1;
    for (int y : g[x]) {
      if (!vis[y])
        dfs(y);
    }
    todo.push_back(x);
  }
  void dfs2(int x, int v) {
    comp[x] = v;
    for (int y : rg[x]) {
      if (comp[y] == -1) {
        dfs2(y, v);
      }
    }
  }
  void gen() {
    for (int i = 0; i < N; i++) {
      if (!vis[i]) dfs(i);
    }
    reverse(todo.begin(), todo.end());
    for (int x : todo) {
      if (comp[x] == -1) {
        dfs2(x, x);
        comps.push_back(x);
      }
    }
  }
};

struct edge {
  int u, v;
  int64_t w;
};

ll gain(ll w) {
    ll k = (ll)((sqrtl(1.0L + 8.0L * w) - 1.0L) / 2.0L);

    return (k + 1) * w
         - k * (k + 1) * (k + 2) / 6;
}


int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m; cin >> n >> m;
  SCC scc;
  scc.init(n);
  vector<edge> edges;
  edges.reserve(m);
  for (int i = 0; i < m; ++i) {
    int u,v; cin >> u >> v;
    ll w; cin >> w;
    u--; v--;
    edges.push_back({u, v, w});
    scc.ae(u, v);
  }
  int s; cin >> s; s--;
  scc.gen();
  vector<ll> in(n);
  vector<vector<pair<int,ll>>> dag(n);
  for (auto& e : edges) {
    int a = scc.comp[e.u];
    int b = scc.comp[e.v];
    if (a==b) {
      in[a] += gain(e.w);
    } else {
      dag[a].push_back({b, e.w});
    }
  }
  vector<ll> dp(n);
  for (int i = (int)scc.comps.size()-1; i >= 0; i--) {
    int c = scc.comps[i];
    dp[c] = in[c];
    for (auto [to, w] : dag[c]) {
      dp[c] = max(dp[c], in[c] + w + dp[to]);
    }
  }
  cout << dp[scc.comp[s]] << '\n';
  return 0;

}
