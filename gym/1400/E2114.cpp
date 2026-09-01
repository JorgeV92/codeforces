#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
vector<int> g[200005];
ll dp1[200005], dp2[200005];
int a[200005];
void dfs(int v, int f) {
  for (auto u : g[v]) {
    if (u == f) continue;
    dp1[u] = a[u] + max(0LL, -dp2[v]);
    dp2[u] = a[u] + min(0LL, -dp1[v]);
    dfs(u, v);
    
  }
} 
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
      g[i].clear();
      a[i] = 0;
      dp1[i] = dp2[i] = 0;
    }
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n-1; i++) {
      int u, v; cin >> u >> v;
      u--; v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dp1[0] = dp2[0] = a[0];
    dfs(0,-1);
    for (int i = 0; i < n; ++i) 
      cout << dp1[i] << ' ';
    cout << '\n';
  }
  return 0;
}
