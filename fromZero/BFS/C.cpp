#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int n, m; std::cin >> n >> m;
    std::unordered_set<int> vis;
    std::queue<int> q;
    q.push(n);
    vis.insert(n);
    int mx = 2 * std::max(n, m);
    int opt = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i =0; i < sz; i++) {
            int v = q.front();
            q.pop();
            if (v == m) {
                std::cout << opt << '\n';
                return 0;
            }
            int u = v * 2;
            int w = v - 1;
            if (u <= mx && vis.count(u) == 0) {
                vis.insert(u);
                q.push(u);
            }
            if (w > 0 && vis.count(w) == 0) {
                vis.insert(w);
                q.push(w);
            }
        }
        opt++;
    }
    std::cout << -1 << '\n';
    return 0;
}   