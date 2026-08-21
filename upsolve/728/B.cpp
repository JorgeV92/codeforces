#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>
using ld = long double;
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<ld> x(n); for (int i = 0; i < n; ++i) std::cin >> x[i];
  std::vector<ld> v(n); for (int i = 0; i < n; ++i) std::cin >> v[i];
  auto canMeet = [&](ld t) -> bool {
    ld left = -std::numeric_limits<ld>::infinity();
    ld right = std::numeric_limits<ld>::infinity();
    for (int i = 0; i < n; ++i) {
      ld le = x[i] - v[i] * t;
      ld ri = x[i] + v[i] * t;
      left = std::max(left, le);
      right = std::min(right, ri);
    }
    return left <= right;
  };
  ld lo = 0.0L, hi = 1e9L;
  for (int i = 0; i < 100; ++i) {
    ld mid = lo + (hi-lo) / 2.0;
    if (canMeet(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  std::cout << std::fixed << std::setprecision(12) << hi << '\n';
  return 0;
}
