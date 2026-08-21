#include <iostream>
#include <vector>
using ll = long long;
int main() {
 std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    int n, k; ll m; std::cin >> n >> k >> m;
    if (k > m) {
      std::cout << "NO\n";
      continue;
    }
    std::cout << "YES\n";
    for (int i = 0; i < n; ++i) {
      if (i % k == 0) {
        std::cout << m - k + 1 << ' ';
      } else {
        std::cout << 1 << ' ';
      }
    }
    std::cout << '\n';
  }
  return 0;
}
