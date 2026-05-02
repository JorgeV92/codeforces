#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdint>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<vector<int>> tree(n); 
        for (int i = 0; i < n-1; i++) {
            int u, v; cin >> u >> v;
            u--; v--;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        vector<int64_t> sz(n);
        for (int i = 0; i < n; i++) if (tree[i].size() == 1) sz[i] = 1;
        {
            auto dfs = [&](auto&& dfs, int u, int f) -> void {
                for (int v : tree[u]) {
                    if (v != f) {
                        dfs(dfs, v,u);
                        sz[u] += sz[v];
                    }
                }
            };dfs(dfs, 0,-1);
        }
        int64_t odd_leaves = 0;
        for (int i = 0; i < n; i++) {
            if (i && sz[i] % 2 == 1) odd_leaves++;
        }
        int64_t ans = odd_leaves;
        if (sz[0] % 2 == 1) {
            auto dfs = [&](auto&& dfs, int v, int f, int64_t path) -> void {
                ans = min(ans, odd_leaves + path);
                for (int u : tree[v]) {
                    if (u != f)
                        dfs(dfs, u,v, path + (sz[u] % 2 == 0 ? 1 : -1));
                }
            }; dfs(dfs, 0, -1,0);
        }
        cout << ans << '\n';
    }
    return 0;
}