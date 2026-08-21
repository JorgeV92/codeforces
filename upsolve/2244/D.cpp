#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    int n, m; std::cin >> n >> m;
    std::vector<ll> a(n); for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::vector<int> b(m); for (int i = 0; i < m; ++i) std::cin >> b[i];
    b.push_back(0);
    sort(b.begin(), b.end());
    std::vector<ll> pref(n+1); for (int i = 0; i < n; ++i) {pref[i+1] = pref[i] + a[i]; }
    ll ans = 0;
    for (int i = 1; i < m+1; i++) {
      int l = b[i-1], r = b[i];
      ll sum = pref[r]  - pref[l];
      ans += std::abs(sum);
    }
    int largest = b.back();
    ans += pref[n] - pref[largest];
    std::cout << ans << '\n';
  
  }
  return 0;
}
