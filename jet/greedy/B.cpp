#include <iostream>
#include <vector>
#include <algorithm>
using i64 = long long;
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n, w; std::cin >> n >> w;
  std::vector<std::pair<int,int>> ab(n);
  for (auto& [a, b] : ab) std::cin >> a >> b;
  std::sort(ab.rbegin(), ab.rend());
  i64 ans = 0;
  for (auto [a, b] : ab) {
    int t = std::min(w, b);
    ans += (i64)a*t;
    w -= t;
    if (w==0) break;
  }
  std::cout << ans << '\n';
  return 0;
}
