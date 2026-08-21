#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
const int64_t MOD = 998244353;
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    int n; std::cin >> n;
    std::vector<int> cnt(n+1);
    std::vector<bool> seen(n+1);
    bool valid = true;
    bool decreasing = false;
    int prev = -1;
    int mx = 0;

    for (int i = 0; i < n-1; i++) {
      int x; std::cin >> x;
      ++cnt[x];
      mx = std::max(mx, x);
      if (i == 0 || x != prev) {
        if (seen[x]) {
          valid = false;
        }
        seen[x] = true;

        if (i > 0) {
          if (x < prev)decreasing = true;
          else {
            if (decreasing) valid = false;
          }
        }
      }
      prev = x;
    }

    if (mx != n-1) {
      valid = false;
    }

    if (!valid) {
      std::cout << 0 << '\n';
      continue;
    }

    int64_t ans = 2;
    int h = cnt[n-1] - 1;

    for (int x = n-2; x >= 2; --x) {
      if (cnt[x] > 0) {
        h += cnt[x] - 1;
      } else {
        if (h == 0) {
          ans = 0;
          break;
        }
        ans = ans * h % MOD;
        --h;
      }
    }

    std::cout << ans << '\n';
  }
  return 0;
}
