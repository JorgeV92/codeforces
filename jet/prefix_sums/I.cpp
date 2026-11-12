#include <iostream>
#include <vector>
#include <unordered_map>
using i64 = long long; 
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n, k; std::cin >> n >> k;
  std::vector<i64> a(n); for (auto& x : a) std::cin >> x;
  std::unordered_map<i64, i64> mp; mp[0] = 1;
  i64 pref = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    pref = (pref + a[i]) % k;
    if (pref<0) pref += k;
    ans += mp[pref];
    mp[pref]++;
  }
  std::cout << ans << '\n';
  return 0;
}
