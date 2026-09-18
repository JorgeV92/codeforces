#include <iostream>
#include <vector>
#include <queue>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < n-1; ++i) {
        int p; std::cin >> p; p--;
        g[p].push_back(i+1);
    }
    std::queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (g[v].size() == 0) continue;
        int leafs = 0;
        for (int u : g[v]) {
            if (g[u].size() == 0) {
                leafs += 1;
            } else {
                q.push(u);
            }
        }
        if (leafs < 3) {
            std::cout << "No\n";
            return 0;
        } 
    }
    std::cout << "Yes\n";
    return 0;
}