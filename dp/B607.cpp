#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> C(n); for (int i = 0; i < n; ++i) cin>> C[i];
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    for (int i = 0; i < n; ++i) dp[i][i+1] = 1;
    for (int i = 0; i < n-1; ++i) 
        dp[i][i+2] = (C[i] == C[i+1] ? 1 : 2);
    for (int l = 3; l <= n; ++l) {
        for (int i = 0; i + l <= n; ++i) {
            int j = i+l;
            int v = l;
            for (int k = i+1; k < j; ++k) {
                v = min(v, dp[i][k] + dp[k][j]);
            }
            if (C[i] == C[j-1]) 
                v = min(v, dp[i+1][j-1]);

            dp[i][j] = v;
        }
    }
    cout << dp[0][n] << '\n';
    return 0;
}   

