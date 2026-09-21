#include <iostream>
#include <vector>
#include <queue>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int t; std::cin >> t;
    while (t--) {
        int n; std::cin >> n;
        std::vector<int> a(n); for (int& x : a) { std::cin >> x; x--; }
        std::vector<std::vector<int>> g(n);
        for (int i = 0; i < n; ++i) {
            int j = a[i];
            if (a[j] == i && i > j) continue;
            g[i].push_back(j);
            g[j].push_back(i);
        }
        std::vector<bool> vis(n);
        int compn = 0;
        int cycles = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            ++compn;
            std::queue<int> q;
            q.push(i);
            vis[i] = true;
            bool cycle = true;
            while (!q.empty()) {
                int v= q.front();
                q.pop();
                if (g[v].size() !=2) cycle = false;
                for (int u : g[v]) {
                    if (!vis[u]) {
                        vis[u] = true;
                        q.push(u);
                    }
                }
            }
            if (cycle) cycles++;
        }
        int mx = compn;
        int mn = cycles;
        if (compn > cycles) ++mn;
        std::cout << mn << ' ' << mx << '\n';
    }
    return 0;
}