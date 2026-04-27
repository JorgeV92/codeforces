#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin>>T;
    while (T--) {
        int n; cin>>n;
        string t, b; cin>>t>>b;
        vector<int> dp(n+1,1e9);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int v = (t[i-1] != b[i-1]);
            dp[i] = min(dp[i], dp[i-1] + v);
            if (i >= 2) {
                int h = (t[i-2] != t[i-1]) + (b[i-2] != b[i-1]);
                dp[i] = min(dp[i], dp[i-2] + h);
            }
        }
        cout<<dp[n]<<'\n';
    }

    return 0;
}