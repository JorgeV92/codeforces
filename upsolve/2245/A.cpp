#include <iostream>
#include <vector>
#include <string>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    int n, k; std::cin >> n >> k;
    std::string s; std::cin >> s;
    if (2 * k > n) {
      std::cout << -1 << '\n';
      continue;
    }
    int ans = 0;
    for (int i = 0; i < k; ++i) {
      if (s[i] != 'R') ans++;
      if (s[n-i-1] != 'L') ans++;
    }
    std::cout << ans << '\n';
  }
  return 0; 
}
