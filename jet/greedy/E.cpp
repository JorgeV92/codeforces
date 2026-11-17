#include <iostream>
#include <vector>
#include <algorithm>
using i64 = long long;
struct ses {
  i64 l , r;
  int id;
};
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<ses> T(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> T[i].l >> T[i].r;
    T[i].id = i+1;
  }
  std::sort(T.begin(), T.end(), [&](const auto& a, const auto& b) {
    return a.r < b.r;
  });
  std::vector<int> ans;
  i64 last = -1;
  for (int i = 0; i < n; ++i) {
    if (T[i].l >= last) {
      ans.push_back(T[i].id);
      last = T[i].r;
    }
  }
  std::cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) std::cout << ans[i] << ' ';
  std::cout << '\n';

  return 0;
}
