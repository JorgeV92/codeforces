#include <iostream>
#include <vector>
#include <string>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    int mx = 0;
    int r = 0;
    while (r < n) {
      if (s[r] != '#') {
        r++;
        continue;
      }
      int  l = r;
      while (r < n && s[r] == '#') r++;
      mx = std::max(mx, r-l);
    }
    std::cout << (mx+1)/2 << '\n';
  }
  return 0;
}
