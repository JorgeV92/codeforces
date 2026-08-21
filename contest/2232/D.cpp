#include <functional>
#include <iostream>
#include <vector>
#include <array>
#include <functional>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >>T;
  while (T--) {
    int n; std::cin >> n;
    std::vector<int> a(n+1); for (int i = 1; i <= n; i++) std::cin >> a[i];
    std::vector<std::array<int, 3>> ans;
    bool ok = true;
    for (int i = 1; i <= n; ++i) {
      if (a[i] > i-1) 
          ok = false;
    }
    if (!ok) {
      std::cout << "NO\n";
      continue;
    }

    std::function<void(int,int,int)> dfs = [&](int k, int s, int t) -> void {
      if (k <= 0) return;
      int u = 6 - s  - t;
      if (a[k] == 0) {
        dfs(k-1, s, u);
        ans.push_back({k, s, t});
        dfs(k-1, u, t);
      }  else {
        int m = k - 1 - a[k];
        dfs(m, s, u);
        ans.push_back({k, s, t});
        dfs(m, u, s);
        dfs(k-1,s, t);

      }
    };

    dfs(n, 1, 3);
    std::cout << "YES\n";
    std::cout << ans.size() << '\n';
    for (auto& [id, from ,to] : ans) {
      std::cout << id << ' ' << from << ' ' << to << '\n';
    }
  }

  return 0;
}
