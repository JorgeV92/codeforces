#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <string>
using namespace std;
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    string s; cin >> s;
    vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
      vector<vector<int>> ndp(n+1, vector<int>(n+1, INT_MAX));
      for (int cnt_f = 0; cnt_f <= i; ++cnt_f) {
        for (int cur_s = 0; cur_s <= i; ++cur_s) {
          if (s[i] != 'T') {
            ndp[cnt_f+1][cur_s+1] = min(ndp[cnt_f+1][cur_s+1], max(dp[cnt_f][cur_s], cur_s+1));
          }
          if (s[i] != 'F') {
            ndp[cnt_f][max(0,cur_s-1)] = min(ndp[cnt_f][max(0,cur_s-1)], dp[cnt_f][cur_s]);
          }
        }
      }
      swap(dp, ndp);
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
        ans = max(ans, i - dp[i][j]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
