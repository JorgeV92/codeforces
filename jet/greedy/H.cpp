#include <iostream>
#include <vector>
#include <algorithm>
using i64 = long long;
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n; std::cin >> n; 
  std::vector<std::pair<int,int>> T(n);
  for (auto& [a, b] : T) std::cin >> a >> b;
  std::sort(T.begin(), T.end(), [&](const auto& a, const auto& b) {
    return a.first < b.first;
  });
  i64 t = 0, ans = 0;
  for (int i = 0; i < n; ++i) {
    t += T[i].first;
    ans += T[i].second - t;
  }
  std::cout << ans << '\n';

  return 0;
}
