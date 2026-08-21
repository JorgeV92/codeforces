#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <functional>
const int mod = 1e9+7;
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >>T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> L(n), R(n);
        for (int i = 0; i < n; i++) {
            cin>>L[i]>>R[i];
            L[i]--; R[i]--;
        }
        vector<int64_t> dp(n);

        function<int64_t(int)> dfs1 = [&](int v) -> int64_t {
            if (L[v] == -1) 
                return dp[v] = 1;
            dp[v] = (dfs1(L[v]) + dfs1(R[v]) + 3) % mod;
            return dp[v];
        }; dfs1(0);

        function<void(int)> dfs2 = [&](int v) -> void {
            if (L[v] == -1) return;
            dp[L[v]] = (dp[L[v]] + dp[v]) % mod;
            dp[R[v]] = (dp[R[v]] + dp[v]) % mod;
            dfs2(L[v]);
            dfs2(R[v]);
        }; dfs2(0);

        for (int i = 0; i < n; i++) {
            cout << dp[i] << " \n"[i+1==n];
        }
    }
    return 0;   
}