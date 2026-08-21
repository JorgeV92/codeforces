#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
        vector<char> dp(n+1, false);
        dp[0] = 1;
        for (int i = 0; i <= n; ++i) {
            if (i && i - a[i-1] - 1 >= 0)  {
                dp[i] |= dp[i - a[i-1] - 1];
            }
            if (i < n && i + a[i] + 1 <= n) {
                dp[i + a[i] + 1] |= dp[i];
            }
        }
        cout << (dp[n] ? "YES" : "NO") << '\n';
    }
    return 0;
}