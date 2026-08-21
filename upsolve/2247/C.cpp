#include <iostream>
#include <numeric>
#include <vector>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int  T; std::cin >> T;
  while (T--) {
    int n; std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (int i = 0; i < n; ++i) std::cin >> b[i];
    if (a == b) {
      std::cout << 0 << '\n';
      continue;
    }
    int sum_a = std::accumulate(a.begin(), a.end(), 0);
    int sum_b = std::accumulate(b.begin(), b.end(), 0);
    if (sum_a == 0) {
      std::cout << -1 << '\n';
      continue;
    }
    if (sum_b == n) {
      std::cout << -1 << '\n';
      continue;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i] && a[i] == 1) cnt++;
    }
    if (cnt % 2 == 1) {
      std::cout << 1 << '\n';
    } else {
      std::cout << 2 << '\n';
    }
  }
  return 0;
}
