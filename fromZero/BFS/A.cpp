#include <iostream>
#include <vector>
#include <queue>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector<char> vis(n);
    std::priority_queue<int, std::vector<int>, std::greater<int>> h;
    std::vector<int> ans;
    h.push(0);
    while (!h.empty()) {
        auto v = h.top();
        h.pop();
        if (vis[v]) continue;
        ans.push_back(v);
        vis[v] = true;
        for (auto u : g[v]) {
            if (!vis[u]) {
                h.push(u);
            }
        }
    }
    for (auto x : ans) {
        std::cout << x+1 << ' ';
    }
    std::cout << '\n';
    return 0;
}