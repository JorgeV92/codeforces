#include <iostream>
#include <vector>
struct elem {
  int l, r;
  int u, v;
};
void solve() {
  int n; std::cin >> n;
  std::vector<elem> a(n);
  for (auto& [l,r,u,v] : a) {
    std::cin >> l >> r >> u >> v;
  }

  auto check = [&](int m) -> bool {
    int j = 1;
    for (const auto& [l, r, u, v] : a) {
      int left = j;
      int right = m - j + 1;
      bool left_good = left < l || left > r;
      bool right_good = right < u || right > v;
      if (left_good && right_good) {
        ++j;
        if (j == m+1) {
          return true;
        }
      }
    }
    return false;
  };

  for (int m = n; m >= 1; m--) {
    if (check(m)) {
      std::cout << m << '\n';
      return;
    }
  }
  std::cout << 0 << '\n';
}
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
