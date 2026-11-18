#include <iostream>
#include <vector>
#include <algorithm>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n, m; std::cin >> n >> m;
  std::vector<std::pair<int,int>> A(n);
  for (auto& [l, r] : A) std::cin >> l >> r; 
  std::sort(A.begin(), A.end(), [&](const auto& a, const auto& b) {
    return a.second < b.second;
  });
  int at = 0, cov = 0, ans = 0;
  while (cov < m) {
    int best = cov;
    while (at < n && A[at].first <= cov) {
      best = std::max(best, A[at].second);
      at++;
    }
    if (best == cov) {
      std::cout << -1 << '\n';
      return 0;
    }
    cov = best;
    ans++;
  }
  std::cout << ans << '\n';
  return 0;
}
