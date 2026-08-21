#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    int n; std::cin >> n;
    std::vector<int> a(n); for (int i = 0; i < n; ++i) std::cin >> a[i];
    if (n == 1) {
      std::cout << 0 << '\n';
      continue;
    }
    int ans = -1;
    for (int z = 0; z < 2; z++, std::reverse(a.begin(), a.end())) {
      int prv = -1;
      int mn = a[0];
      int mx = a[0];
      for (int i = 1; i < n; ++i) {
        if (a[i] > mx) {
          mx = a[i];
          if (prv != 0) {
            ans++;
            prv = 0;
          }
        } else if (a[i] < mn) {
          mn = a[i];
          if (prv != 1) {
            ans++;
            prv = 1;
          }
        }
      }
    }
    std::cout << ans << '\n';
  }
  return 0;
}
