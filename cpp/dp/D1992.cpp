#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n, m, k; cin >> n >> m >> k;
        string s; cin >> s;
        s = " " + s; 
        vector<int> dp(n+2, 1e9);
        dp[0] = 0;
        for (int i = 0; i <= n; i++) {
            if (dp[i] > k) continue;
            if (i >= 1 && s[i] == 'C') continue;
            if (i == 0 || s[i] == 'L') {
                for (int j = i + 1; j <= min(n+1, i+ m); j++) {
                    if (j == n+1 || s[j] != 'C') {
                        dp[j] = min(dp[j], dp[i]);
                    }
                }
            } else if (s[i] == 'W') {
                int j = i+1;
                if (j==n+1 || s[j] != 'C') {
                    dp[j] = min(dp[j], dp[i]+1);
                }
            }
        }
        cout << (dp[n+1] <= k ? "YES" : "NO") << "\n";
    }
    return 0;
}