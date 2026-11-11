#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
using i64 = long long;
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n; std::cin >> n;
  i64 mx = LLONG_MIN, cur = 0;
  for (int i = 0; i < n; i++) {
    i64 x; std::cin >> x;
    cur = std::max(x, cur + x);
    mx = std::max(mx, cur);
  }
  std::cout << mx << '\n';
  return 0;
}
