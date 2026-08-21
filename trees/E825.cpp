#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
const int maxn = 100007;
std::vector<int> radj[maxn];
int out[maxn];
int N, M;
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    std::cin >> N >> M;
    for (int i =0; i < N; ++i) {
        radj[i].clear();
        out[i] = 0;
    }
    for (int i = 0; i < M; ++i) {
        int u, v; std::cin >> u >> v;
        u--, v--;
        radj[v].push_back(u);
        out[u]++;
    }
    std::priority_queue<int> h;
    for (int i = 0; i < N; ++i) 
        if (!out[i])
            h.push(i);

    std::vector<int> ans(N);
    int id = N;
    while (!h.empty()) {
        auto u = h.top();
        h.pop();
        ans[u] = id--;
        for (int v : radj[u]) {
            if (!--out[v]) 
                h.push(v);
        }
    }
    for (int v : ans) std::cout << v << ' '; 
    std::cout << '\n';
    return 0;
}
