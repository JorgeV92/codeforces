#include <iostream>
#include <iostream>
#include <vector>
#include <cstdint>
#include <string>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    int64_t n, x, s; std::cin >> n >> x >> s;
    std::string u; std::cin >> u;
    int64_t ans = 0, l = 0, r= 0;
    for (char c : u) {
      if (c == 'A') {
        if (x*s == ans) continue;
        ans++;
        if (ans > l*s) l++;
        r = std::min(r+1, x);
      } else if (c == 'I') {
        if (l == x) continue;
        ans++;
        l++;
        r = std::min(r+1, x);
      } else if (c == 'E') {
        if (ans == r*s) continue;
        ans++;
        if (ans >l * s) l++;
      }
    }
    std::cout << ans << '\n';
  }
  return 0;
}
