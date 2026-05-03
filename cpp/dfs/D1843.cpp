#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdint>

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    auto justice = [&]() -> void {
        int T; std::cin >> T;
        while (T--) {
            int n; std::cin >> n;
            std::vector<std::vector<int>> tree(n);
            for (int i = 0; i < n-1; i++) {
                int u, v; std::cin >> u >> v;
                u--; v--;
                tree[u].push_back(v);
                tree[v].push_back(u);
            } 
            std::vector<int64_t> sz(n);
            [&](this auto&& self, int v, int f) -> void {
                bool leaf = true;
                for (auto u : tree[v]) {
                    if (u != f) {
                        leaf = false;
                        self(u, v);
                        sz[v] += sz[u];
                    }
                }
                if (leaf) {
                    sz[v] = 1LL;
                }
            }(0,-1);
            int q; std::cin >> q;
            while (q--) {
                int x, y; std::cin >> x >> y;
                x--; y--;
                std::cout << (sz[x] * sz[y]) << "\n";
            }
        }
    }; justice();
    return 0;   
}