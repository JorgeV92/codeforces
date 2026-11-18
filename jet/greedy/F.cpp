#include <iostream>
#include <vector>
#include <algorithm>
using i64 = long long;
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n, m; std::cin >> n >> m;
  std::vector<std::pair<int,int>> A(m);
  for (auto& [l, r] : A) { std::cin >> l >> r; r--; }
  std::sort(A.begin(), A.end(), [&](const auto& a, const auto& b) { return a.second < b.second; });
  int end = 0, ans = 0;
  for (int i = 0; i < m; ++i) {
    if (end < A[i].first) {
      ans++;
      end = A[i].second;
    }
  }
  std::cout  << ans << '\n';
  return 0;
}
