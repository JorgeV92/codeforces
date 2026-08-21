#include <iostream>
#include <vector>
#include <string>
const int INF = 1000000007;
std::string s, t;
std::vector<std::vector<int>> dp;
int nxt[100001][26];
int F[100001];
void kmp_auto() {
  F[0] = F[1] = 0;
  for (int i = 2; i <= (int)t.size(); i++) {
    int j = F[i-1];
    for (;;) {
      if (t[j] == t[i-1]) {
        F[i] = j+1;
        break;
      }
      if (j == 0) {
        F[i] = 0;
        break;
      }
      j = F[j];
    }
  }
  for (int i = 0;  i <= (int)t.size(); i++) {
    for (int j = 0; j < 26; ++j) {
      if (i < (int)t.size() && t[i] == ('a' + j)) nxt[i][j] = i+1;
      else nxt[i][j] = nxt[F[i]][j];
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  std::cin >> s >> t; dp.resize(s.size()+1);
  for (int i = 0; i <= s.size(); ++i) {
    dp[i].resize(t.length()+1);
    for (int j = 0; j <= (int)t.size(); ++j) {
      dp[i][j] = -INF;
    }
  }
  kmp_auto();
  dp[0][0] = 0;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (s[i] == '?') {
      for (int j = 0; j <= (int)t.size(); ++j) {
        for (int k= 0; k < 26 ; ++k) {
          int n = nxt[j][k];
          if (n == (int)t.size()) dp[i+1][n] = std::max(dp[i+1][n], dp[i][j] + 1);
          else dp[i+1][n] = std::max(dp[i+1][n], dp[i][j]);
        }
      }
    } else {
      for (int j = 0; j <= t.size(); ++j) {
        int n = nxt[j][s[i]-'a'];
        if (n == (int)t.size()) dp[i+1][n] = std::max(dp[i+1][n], dp[i][j]+1);
        else dp[i+1][n] = std::max(dp[i+1][n], dp[i][j]);
      }
    }
  }
  int ans = 0;
  for (int j = 0; j <= (int)t.size(); ++j) ans = std::max(ans, dp[s.length()][j]);
  std::cout << ans << '\n';

  return 0;
}
