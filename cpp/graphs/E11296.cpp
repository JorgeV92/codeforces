#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    auto jorgee = [&]() -> void {
        int n; std::cin >> n;
        std::string s; std::cin >> s;
        std::vector<std::vector<int>> g(n);
        for (int i = 0; i < n; i++) {
            for (int j = i +1; j < n; j++) {
                if (s[i] > s[j]) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        std::vector<int> side(n,-1);
        bool is_bipartite = true;
        std::queue<int> q;

        for (int st = 0; st < n; st++) {
            if (side[st] == -1) {
                q.push(st);
                side[st] = 0;

                while (!q.empty()) {
                    int v = q.front(); 
                    q.pop();
                    for (auto u : g[v]) {
                        if (side[u] == -1) {
                            side[u] = side[v] ^ 1;
                            q.push(u);
                        } else {
                            is_bipartite &= side[u] != side[v];
                        }
                    }
                }
            }
        }
        if (is_bipartite) {
            std::cout << "YES\n";
            for (int x : side) {
                std::cout << x;
            }
            std::cout << '\n';
        } else {
            std::cout << "NO\n";
        }
    }; jorgee();
    return 0;
}

void other() {
    int n;
    std::stirng s;
    std::vector<int> dp, f;
    std::cin >> n >> s;
    f.assign(26, 0);
    dp.resize(n);
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = s[i] - 'a' + 1; j < 26; j++) {
            dp[i] = std::max(dp[i], f[j] + 1);
        }
        f[s[i]-'a'] = dp[i];
    }
    intn ans = *std::max_element(dp.begin(), dp.end());
    if (ans > 2) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
        for (int i = 0; i < n; i++) 
            std::cout << dp[i] - 1;
        std::cout << "\n";
    }
}