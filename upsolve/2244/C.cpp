#include <iostream>
#include <vector>
#include <numeric>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    int n, x, y; std::cin >> n >> x >> y;
    std::vector<int> p(n); for (int i = 0; i <n; ++i) std::cin >> p[i];
    int g = std::gcd(x, y);
    bool good = true;
    for (int i = 0; i < n; ++i) {
      int j = i + 1;
      if (p[i] % g != j % g) {
        good = false;
        break;
      }
    }
    std::cout << (good ? "YES" : "NO") << '\n';
  }
  return 0;
}
