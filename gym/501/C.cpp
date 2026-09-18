#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int> deg(n), s(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> deg[i] >> s[i];
    }
    std::queue<int> q;
    for (int i = 0; i < n; i++) if (deg[i]==1) q.push(i);
    std::vector<std::pair<int,int>> edges;
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        if (deg[v] != 1) continue;
        int u = s[v];
        edges.push_back({v, u});
        deg[v]--;
        deg[u]--;
        s[u] ^= v;
        if (deg[u] == 1) q.push(u);
    }
    std::cout << edges.size() << '\n';
    for (auto& [u, v] : edges) {
        std::cout << u << ' ' << v << '\n';
    }
    return 0;
}