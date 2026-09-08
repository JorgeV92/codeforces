#include <iostream>
#include <vector>
using namespace std; 
const int inf = 1e9;
void solve() {
    int n;
    string s; cin >> n >> s;
    vector<vector<int>> dp(n+1,vector<int>(7,inf)); 
    dp[0][3] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = -3; j <= 3; ++j) {
            int cur = dp[i][j+3];
            if (cur == inf) continue;
            for (int nxt = -3; nxt <= 3; ++nxt) {
                if (nxt == j) continue;
                if (s[i] == '+' && nxt <= 0) continue;
                if (s[i] == '-' && nxt >= 0) continue;
                if (s[i] == '0' && nxt != 0) continue;
                int nw = max(cur, abs(nxt-j));
                dp[i+1][nxt+3] = min(dp[i+1][nxt+3], nw);
            }
        }
    }
    int ans = inf;
    for (int p = 0; p < 7; ++p) {
        ans = min(ans, dp[n][p]);
    }
    cout << (ans == inf ? -1 : ans) << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>> t;
    while (t--) {
        solve();
    }
    return 0;
}