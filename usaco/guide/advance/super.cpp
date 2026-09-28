#include <iostream>
#include <vector>
#include <cstdint>
#include <array>
typedef long long ll;
const ll INF = 4e18;
int n;
ll b;
std::vector<ll> cost, disc; 
std::vector<std::vector<int>> child;
std::vector<std::array<std::vector<ll>, 2>> dp;

void dfs(int u) {
    dp[u][0] = {0, cost[u]};
    dp[u][1] = {INF, cost[u]-disc[u]};
    for (int v : child[u]) {
        dfs(v);
        int su = (int)dp[u][0].size() - 1, sv = (int)dp[v][0].size() - 1;
        std::vector<ll> n0(su + sv + 1, INF), n1(su + sv + 1, INF);
        for (int j = 0; j <= su; j++) {
            for (int k = 0; k <= sv; k++) {
                if (dp[u][0][j] < INF/2 && dp[v][0][k] < INF/2)
                    n0[j+k] = std::min(n0[j+k], dp[u][0][j] + dp[v][0][k]);
                ll best = std::min(dp[v][0][k], dp[v][1][k]);
                if (dp[u][1][j] < INF/2 && best < INF/2)
                    n1[j+k] = std::min(n1[j+k], dp[u][1][j] + best); 
            }
        }
        dp[u][0] = std::move(n0);
        dp[u][1] = std::move(n1);
        std::vector<ll>().swap(dp[v][0]);
        std::vector<ll>().swap(dp[v][1]);
    }
}

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    std::cin >> n >> b;
    cost.assign(n,0); disc.assign(n,0);
    child.assign(n,{}); dp.assign(n,{});
    for (int i = 0; i < n; ++i) {
        if (i == 0) 
            std::cin >> cost[i] >> disc[i];
        else {
            int x; std::cin >> cost[i] >> disc[i] >> x;
            child[x-1].push_back(i);
        }
    }
    dfs(0);
    int ans = 0;
    for (int j = 0; j <= n; ++j) 
        if (std::min(dp[0][0][j], dp[0][1][j]) <= b) ans = j;
    std::cout << ans << '\n';
    return 0;   
}