#include <iostream>
#include <vector>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    int n, z; std::cin >> n >> z;
    int ans = 0;
    for (int i = 0; i < n; ++i) { int x; std::cin >> x; ans = std::max(ans, x | z); }
    std::cout << ans << '\n';
  }
  return 0;
}
