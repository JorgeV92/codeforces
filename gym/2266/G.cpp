#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdint>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n;
        std::vector<int64_t> a(n), b(n);
        for (auto& x : a) std::cin >> x;
        for (auto& x : b) std::cin >> x;
        std::vector<std::vector<int>> adj(n);
        for (int i= 0; i < n-1; i++) {
            int u, v; std::cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        std::vector<int64_t> g(n);

        auto dfs = [&](auto&& self, int u, int p) -> void {
            int64_t sum = 0;
            int64_t cur_gcd = b[u];
            for (int v : adj[u]) {
                if (v == p) continue;
                self(self, v, u);
                sum += a[v];
                if (g[v] != b[v]) cur_gcd = std::gcd(cur_gcd, g[v]);
            }
            cur_gcd = std::gcd(cur_gcd, sum);
            g[u] = cur_gcd;
        }; dfs(dfs, 0, -1);

        int64_t ans = 0;
        for (int u = 0; u < n; ++u) {
            int64_t steps = (b[u]-1-a[u]) / g[u];
            int64_t mx = a[u] + steps * g[u];
            ans += mx;
        }
        std::cout << ans << '\n';
    }
}