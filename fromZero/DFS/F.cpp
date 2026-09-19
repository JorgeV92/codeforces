#include <iostream>
#include <vector>
#include <unordered_map>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int N; std::cin >> N;
    std::unordered_map<int, std::vector<int>> g;
    for (int i = 0; i < N; ++i) {
        int u, v; std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int s = -1;
    for (const auto& [u, ne] : g) {
        if (ne.size() == 1) {
            s = u;
            break;
        }
    }
    int prev = -1;
    int cur = s;
    while (true) {
        std::cout << cur << ' ';
        int nxt = -1;
        for (int v : g[cur]) {
            if (v != prev) {
                nxt = v;
                break;
            }
        }
        if (nxt == -1) break;
        prev = cur;
        cur = nxt;
    }
    std::cout << '\n';

    return 0;   
}