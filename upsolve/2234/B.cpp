#include <iostream>
#include <vector>
#include <cstdint>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);  
  int T; std::cin >> T;
  while (T--) {
    int64_t n; std::cin >> n;
    if (n == 10) {
      std::cout << -1 << '\n';
    } else if (n % 12 == 10) {
      std::cout << 22 << ' ' << n-22 << '\n';
    } else {
      std::cout << n%12 << ' ' << n-(n%12) << '\n';
    }
  }
  return 0;
}
