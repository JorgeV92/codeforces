#include <iostream>
#include <vector>
#include <string>
#include <stack>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int t; std::cin >> t;
  while (t--) {
    int n; std::string s;
    std::cin >> n >> s;
    int seg = 1;
    for (int i = 1; i < n; ++i) {
      seg += (s[i] != s[i-1]);
    }
    int ans = seg;
    for (int i = 1; i < n-1; i++) {
      int t = seg - (s[i-1] != s[i]) - (s[i] != s[i+1]) + (s[i-1] != s[i+1]);
      ans = std::min(ans, t);
    }
    std::cout << ans << '\n';
  }
  return 0;
}
