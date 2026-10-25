#include <algorithm>
#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int N, M; std::cin >> N >> M;
        std::vector<std::vector<int>> graph(N + 1);
        for (int i = 1; i < N; i++) {
            int X, Y; std::cin >> X >> Y;
            graph[X].push_back(Y);
            graph[Y].push_back(X);
        }
        std::vector<int> V(M);
        for (int &x : V) std::cin >> x;
        std::vector<int> branch(N + 1);
        auto dfs = [&](auto &&self, int u, int p) -> void {
            for (int v : graph[u]) {
                if (v == p) continue;
                branch[v] = (u == 1 ? v : branch[u]);
                self(self, v, u);
            }
        }; dfs(dfs, 1, 1);
        std::vector<int> dist(N + 1, -1);
        dist[N] = 0;
        auto getDist = [&](auto &&self, int u, int p) -> void {
            for (int v : graph[u]) {
                if (v == p) continue;
                dist[v] = dist[u] + 1;
                self(self, v, u);
            }
        }; getDist(getDist, N, N);
        int ans = dist[1];
        for (int v : V) {
            if (branch[v] == branch[N]) ans = std::max(ans, dist[v] + 1);
        }
        std::cout << ans << '\n';
    }
    return 0;
}
