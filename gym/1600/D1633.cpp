#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int maxn = 1000;
const int inf = 1e9;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    vector<int> cost(maxn+1,inf);
    cost[1] = 0;
    for (int v = 1; v <= maxn; ++v) {
        for (int x = 1; x <= v; x++) {
            int nxt = v + v/x;
            if (nxt <= maxn) {
                cost[nxt] = min(cost[nxt], cost[v] +1);
            }

        }
    }
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> b(n), c(n);
        for (int& x : b) cin >> x;
        for (int& x : c) cin >> x;
        int total = 0;
        for (int x : b) total += cost[x];
        k = min(k, total);
        vector<ll> dp(k+1, 0);
        for (int i = 0; i < n; ++i) {
            int w = cost[b[i]];
            int val = c[i];
            for (int j = k; j >= w; j--) {
                dp[j] = max(dp[j], dp[j-w] + val);
            }
        }
        cout << dp[k] << '\n';
    }
    return 0;
}