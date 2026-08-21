#include <iostream>
#include <vector>
#include <numeric>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    int n, k; std::cin >> n >> k;
    std::vector<int> b(n); for (int i = 0; i < n; ++i) std::cin >> b[i];
    int res = 2023;
    for (int i = 0; i < n; ++i) {
      if (res % b[i]) {
        std::cout << "NO\n";
        goto end;
      }
      res /= b[i];
    }
    std::cout << "YES\n";
    for (int i = 0; i < k; ++i) {
      if (i == 0)
        std::cout << res << ' ';
      else 
        std::cout << 1 << ' ';
    }
    std::cout << '\n';
  end:; 
  }
  return 0;
}
