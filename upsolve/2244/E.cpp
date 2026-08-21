#include <iostream>
#include <vector>
#include <string>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    int n, q; std::cin >> n >> q;
    std::string s; std::cin >> s;
    std::vector<int> pref(n+1);
    for (int i = 1; i < n; ++i) {
      pref[i+1] = pref[i] + (s[i-1] == s[i]);
    }
    while (q--) {
      int l, r, k; std::cin >> l >> r >> k;
      int c = pref[r] - pref[l];
      if ((c+1)/2 <= k) std::cout << "YES\n";
      else std::cout << "NO\n";
    }
  }
  return 0;
}
