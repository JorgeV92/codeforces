#include <iostream>
#include <vector>

void solve() {
    int n; std:: cin >> n;
    std::vector<std::vector<int>> adj(n);
    std::vector<int> in(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, x, y;
        std::cin >> u >> v >> x >> y;
        u--; v--;
        if (x > y) {
            adj[v].push_back(u);
            in[u]++;
        } else  {
            adj[u].push_back(v);
            in[v]++;
        }
    }

    std::vector<int> q;
    for (int i = 0; i< n; i++) {
        if (!in[i]) q.push_back(i);
    }

    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        int x = q[i];
        p[x] = i;
        for (auto v : adj[x]) {
            if (!--in[v]) {
                q.push_back(v);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << p[i] + 1 << " \n"[i==n-1];
    }
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}