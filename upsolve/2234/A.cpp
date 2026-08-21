#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    int n ; std::cin >> n;
    std::vector<int64_t> b(n); for (int i = 0; i < n; ++i) std::cin >> b[i];
    std::sort(b.begin(), b.end(), std::greater<int64_t>());
    bool good = true;
    for (int i = 0; i < n-2; ++i) {
      if (b[i+2] != (b[i] % b[i+1])) {
        good = false;
        break;
      }
    }
    if (good) {
      std::cout << b[0] << ' ' << b[1] << '\n';
    } else {
      std::cout << -1 << '\n';
    }
  }
  return 0;
}
