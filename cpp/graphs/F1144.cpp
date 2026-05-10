#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    auto jorgee= [&]() -> void {
        int n, m; std::cin >> n >> m;
        std::vector<std::vector<int>> adj(n);
        std::vector<std::pair<int,int>> e;
        for (int i = 0; i < m; i++) {
            int u, v; std::cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            e.push_back({u, v});
        }
        std::vector<int> vis(n,-1);
        bool is_bipartite = true;
        std::queue<int> q;
        for (int st = 0; st < n; st++) {
            if (vis[st] == -1) {
                vis[st] = 0;
                q.push(st);
                while (!q.empty()) {
                    int x = q.front();
                    q.pop();
                    for (int y : adj[x]) {
                        if (vis[y] == -1) {
                            vis[y] = vis[x] ^ 1;
                            q.push(y);
                        } else {
                            is_bipartite &= vis[y] != vis[x];
                        }
                    }
                }
            }
        }
        if (is_bipartite) {
            std::cout << "YES\n";
            for (auto [u, v] : e) {
                if (vis[u] == 0) {
                    std::cout << '0';
                } else {
                    std::cout << '1';

                }
            }
            std::cout << '\n';
        } else {
            std::cout << "NO\n";
        }
    }; jorgee();
    return 0;
}