#include <climits>
#include <cstddef>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cstring>
using namespace std;
const int64_t mod = 1'000'000'007LL;
int N, M;
bool vis[100002];
vector<int> g[100002], rg[100002];
vector<int> order;
vector<int64_t> cost;

void dfs1(int v) {
  vis[v] = true;
  for (int u : g[v]) {
    if (!vis[u])
      dfs1(u);
  }
  order.push_back(v);
}

void dfs2(int v, int64_t& mn_cost, int64_t& mn_cnt) {
  vis[v] = true;
  if (cost[v] < mn_cost) {
    mn_cost = cost[v];
    mn_cnt = 1; 
  } else if (cost[v] == mn_cost) {
    mn_cnt++;
  }
  for (int u : rg[v]) {
    if (!vis[u]) 
      dfs2(u, mn_cost, mn_cnt);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N;
  cost.resize(N);
  for (int i = 0; i < N; ++i) cin >> cost[i];
  cin >> M;
  for (int i = 0; i < M; ++i) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    rg[v].push_back(u);
  }
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < N; ++i) {
    if (!vis[i])
        dfs1(i);
  }
  reverse(order.begin(), order.end());
  memset(vis, 0, sizeof(vis));
  int64_t total = 0;
  int64_t ways = 1;
  for (int u : order) {
    if (!vis[u]) {
      int64_t mn_cost = INT64_MAX;
      int64_t mn_cnt = 0;
      dfs2(u, mn_cost, mn_cnt);
      total += mn_cost;
      ways = (ways*mn_cnt) % mod;
    }
  }
  cout << total << ' ' << ways << '\n';
  return 0;
}
