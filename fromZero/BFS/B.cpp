#include <iostream>
#include <vector>
#include <queue>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; std::cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector<int> a(n); for (int& x : a) std::cin >> x, x--;
    if (a[0] != 0) {
        std::cout << "No\n";
        return 0;
    }
    std::vector<int> pos(n); for (int i = 0; i < n; ++i) pos[a[i]] = i;
    for (int v = 0; v < n; ++v) {
        std::sort(g[v].begin(), g[v].end(), [&](auto& i, auto& j) { return pos[i] < pos[j]; } );
    }
    std::vector<int> ans;
    std::vector<char> vis(n);
    std::queue<int> q;
    q.push(0);
    vis[0] = 1
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        ans.push_back(v);
        for (auto u : g[v]) {
            if (!vis[u]) {
                vis[u] = 1;
                q.push(u);
            }
        }
    }
    if (ans == a) {
        std::cout << "Yes\n"; 
    } else std::cout << "No\n";

    return 0;
}