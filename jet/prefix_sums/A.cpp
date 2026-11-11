#include <iostream>
#include <vector>
using i64 = long long;
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<i64> a(n); for (int i = 0; i < n; ++i) std::cin >> a[i];
  i64 pref = 0;
  for (int i = 0; i < n; i++) {
    pref += a[i];
    std::cout << pref << ' ';
  }
  std::cout << '\n';
  return 0;
}
