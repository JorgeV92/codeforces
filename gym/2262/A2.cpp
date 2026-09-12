#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std; 
using ll = long long;
const int mod = 1e9+7;
void solve() {
    int n; cin >> n;
    vector<int> A(n); for (int& i : A) cin>>i;
    set<int> S;
    for (int i = 0; i < n; ++i) S.insert(i);
    vector<pair<int,int>> req; 
    for (int i = 1; i <= n; ++i) {
        int m = A.at(i-1);
        int L = m * i;
        int R = (m+1) * i;
        while (true) {
            auto it = S.lower_bound(m*i);
            if (it != S.end() && *it < (m+1)*i) {
                S.erase(it);
            } else {
                break;
            }
        }
        for (int j = 0; j < m; ++j) {
            req.push_back({j*i, (j+1)*i});
        }
    }

    vector<int> v(S.begin(), S.end());
    int M = v.size();
    vector<int>maxL(M+1, -1);
    for (auto [L, R] : req) {
        int l = lower_bound(v.begin(), v.end(), L) - v.begin();
        int r = lower_bound(v.begin(), v.end(), R) - v.begin();
        maxL[r] = max(maxL[r], l);
    }
    for (int i = 1; i <= M; ++i) {
        maxL[i] = max(maxL[i], maxL[i-1]);
    }
    vector<ll> dp(M+2,0);
    vector<ll> pref(M+2,0);
    dp[0] = 1;
    pref[0] = 1;
    for (int i = 0; i <= M; ++i) {
        ll ways = pref[i];
        if (maxL[i] >= 0) {
            ways -= pref[maxL[i]];
            if (ways <0 ) ways += mod;
        }
        dp[i+1] = ways;
        pref[i+1] = pref[i] + dp[i+1];
        if (pref[i+1] >= mod) pref[i+1] -= mod;
    }
    cout << dp[M+1] % mod << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}