#include <iostream>
#include <vector>
using ll = long long;
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while(T--) {
    int n; std::cin >> n;
    std::vector<ll> w(n); for (int i = 0; i < n; i++) std::cin >> w[i];
    if (n % 2 != 0) {
      std::cout << "NO\n";
      continue;
    }
    ll mx = -1e18;
    ll mn = 1e18;
    for (int i = 0; i < n; ++i) {
      int j = i+1;
      if (j % 2 == 1) {
        mn = std::min(mn, w[i]);
      } else {
        mx = std::max(mx, w[i]);
      }
    }
    if (mx + 1 < mn) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }

  }
  return 0;
}
