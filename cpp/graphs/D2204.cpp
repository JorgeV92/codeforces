#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;
        vector<vector<int>> g(N);
        for (int i = 0; i < M; i++) {
            int u, v; cin >> u >> v;
            u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ans = 0;
        vector<int> side(N, -1);
        for (int st = 0; st < N; st++) {
            if (side[st] == -1) {
                queue<int> q;
                q.push(st);
                bool is_bipartite = true;
                int cnt[2]{};
                side[st] = 0;
                while (!q.empty()) {
                    int v = q.front();
                    q.pop();
                    cnt[side[v]]++;
                    for (int u : g[v]) {
                        if (side[u] == -1) {
                            side[u] = side[v] ^ 1;
                            q.push(u);
                        } else {
                            is_bipartite &= side[u] != side[v];
                        }
                    }
                }
                if (is_bipartite) {
                    ans += max(cnt[0], cnt[1]);
                }
            } 
        }
        cout << ans << "\n";
    }
    return 0;
}