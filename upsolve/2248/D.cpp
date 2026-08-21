#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    int n, q; std::cin >> n >> q;
    std::string s, t; std::cin >> s >> t;
    std::vector<int> pref01(n+1), pref10(n+1), prefE(n+1);
    for (int i = 1; i <= n; ++i) {
      pref01[i] = pref01[i-1];
      pref10[i] = pref10[i-1];
      prefE[i] = prefE[i-1];

      char x = s[i-1], y = t[i-1];
      if (x == '0' && y == '1') ++pref01[i];
      else if (x == '1' && y == '0') ++pref10[i];
      else ++prefE[i];
    }
    while (q--) {
      int l, r; std::cin >> l >> r;
      int cnt01 = pref01[r] - pref01[l-1];
      int cnt10 = pref10[r] - pref10[l-1];
      int e = prefE[r] - prefE[l-1];
      if (std::abs(cnt01 - cnt10) <= e) {
        std::cout << "YES\n";
      } else {
        std::cout << "NO\n";
      }
    }
  }
  return 0;
}
