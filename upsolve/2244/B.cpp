#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    int n; std::cin >> n;
    std::vector<ll> a(n); for (int i = 0; i < n; ++i) std::cin >> a[i];
    ll pref = 0;
    bool good = true;
    for (int i = 0; i < n; ++i) {
      pref += a[i];
      ll k = i + 1;
      ll sum = k * (k+1) / 2;
      if (pref < sum) {
        good = false;
        break;
      }
    }
    std::cout << (good ? "YES" : "NO") << '\n';
  }
  return 0;
}
