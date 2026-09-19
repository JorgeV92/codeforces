#include <iostream>
#include <vector>
const int maxn = 200005;
std::vector<int> g[maxn];
int N, M;
bool vis[maxn];

bool dfs(int v) {
    vis[v] = true;
    bool cycle = (g[v].size() == 2);
    for (int u : g[v]) {
        if (!vis[u]) {
            if (!dfs(u)) {
                cycle = false;
            }
        }
    }
    return cycle;
}
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    std::cin >> N >> M;
    for (int i = 0; i < N; i++)  {
        vis[i] = false;
        g[i].clear();
    }
    for (int i = 0; i < M; i++) {
        int u, v; std::cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (!vis[i]) {
            if (dfs(i)) ans++;
        }
    }
    std::cout << ans << '\n';
    return 0;
}