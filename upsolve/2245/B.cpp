#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
using ll = long long;
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    int n; ll c; std::cin >> n >> c;
    std::vector<ll> a(n); for (int i = 0; i < n; ++i) { std::cin >> a[i]; a[i]-= c; }
    std::nth_element(a.begin(), a.begin() + n/2, a.end());
    ll ans = std::accumulate(a.begin()+n/2, a.end(), ll(0));
    for (int i = 0; i < n/2; ++i) {
      ans += std::max(a[i], ll(0));
    }
    std::cout << ans << '\n';

  }
  return 0;
}
