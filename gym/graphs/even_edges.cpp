#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
vector<int> g[100005];
int vis[100005];
int timer = 1;
int odd[100005];
vector<pair<int,int>> edges;

void dfs(int u, int f) {
    vis[u] = timer++;
    for (int v : g[u]) {
        if (v != f) {
            if (vis[v] == 0) {
                dfs(v, u);
                if (odd[v]) {
                    edges.push_back({v, u});
                    odd[v] = 0;
                } else {
                    edges.push_back({u, v});
                    odd[u] ^= 1;
                }
            } else if (vis[u] > vis[v]) {
                edges.push_back({u, v});
                odd[u] ^= 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        if (!vis[i])
            dfs(i, -1);
    }
    if (accumulate(odd, odd+n, 0)) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (const auto& [u, v] : edges) {
            cout << u+1 << ' ' << v+1 << '\n';
        }
    }
    return 0;
}