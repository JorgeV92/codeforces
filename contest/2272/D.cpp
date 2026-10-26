#include <algorithm>
#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int k; std::cin >> k;
        std::vector<int> connector(k + 1, 1);
        int center = 1;
        for (int tree = 1; tree <= k; tree++) {
            int n; std::cin >> n;
            std::vector<std::vector<int>> adj(n + 1);
            for (int i = 1; i < n; i++) {
                int u, v; std::cin >> u >> v;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            if (n == 1) continue;
            center = tree;
            std::vector<int> parent(n + 1), order = {1};
            parent[1] = -1;
            for (int i = 0; i < n; i++) {
                int u = order[i];
                for (int v : adj[u]) {
                    if (v == parent[u]) continue;
                    parent[v] = u;
                    order.push_back(v);
                }
            }
            std::vector<int> excluded(n + 1), included(n + 1);
            for (int i = n - 1; i >= 0; i--) {
                int u = order[i];
                included[u] = 1;
                for (int v : adj[u]) {
                    if (parent[v] != u) continue;
                    excluded[u] += std::max(excluded[v], included[v]);
                    included[u] += excluded[v];
                }
            }
            if (excluded[1] >= included[1]) connector[tree] = 1;
            else {
                for (int v : adj[1]) {
                    if (parent[v] == 1) {
                        connector[tree] = v;
                        break;
                    }
                }
            }
        }
        for (int tree = 1; tree <= k; tree++) {
            if (tree != center) std::cout << center << ' ' << connector[center] << ' ' << tree << ' ' << connector[tree] << '\n';
        }
    }
    return 0;
}
