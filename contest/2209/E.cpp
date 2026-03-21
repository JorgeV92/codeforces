#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <algorithm>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int m = r - l + 1;
        vector<int> Z(m);
        Z[0] = m;
        int L = 0, R = 0;
        for (int i = 1; i < m; i++) {
            if (i <= R) {
                Z[i] = min(R- i + 1, Z[i -L]);
            }
            while (i + Z[i] < m && s[l + Z[i]] == s[l + i + Z[i]]) 
                ++Z[i];
            if (i + Z[i] - 1 > R) {
                L = i;
                R = i + Z[i] - 1;
            }
        }

        vector<int> dp(m+1);
        vector<int> cnt(m+1);
        vector<int> hd(m+2,-1), nxt(m+1,-1);
        int mx = -1;
        int64_t qres = 0;
        dp[0] = 0;

        for (int x = 1; x <= m; x++) {
            int i = x - 1;
            if (Z[i] >= 1) {
                int v = dp[i];
                cnt[v]++;
                if (v > mx) 
                    mx = v;
                int time = i + Z[i] + 1;
                if (time <= m) {
                    nxt[i] = hd[time];
                    hd[time] = i;
                }
            }
            int curr = hd[x];
            while (curr != -1) {
                int v = dp[curr];
                cnt[v]--;
                curr = nxt[curr];
            }
            while (mx >= 0 && cnt[mx] == 0) {
                mx--;
            }
            dp[x] = mx + 1;
            qres += dp[x];
        }
        cout << qres << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;   
}