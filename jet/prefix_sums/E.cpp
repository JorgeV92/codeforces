#include <iostream>
#include <vector>
using i64 = long long;
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n, m, q; std::cin >> n >> m >> q;
  std::vector<i64> a(n); for (auto& x : a) std::cin >> x;
  std::vector<i64> d(n+1);
  while (m--) {
    int l, r; i64 x;
    std::cin >> l >> r >> x;
    d[l-1] += x;
    d[r] -= x;
  }
  std::vector<i64> pref(n+1); 
  i64 cur = 0; 
  for (int i = 0; i < n; i++) { cur += d[i]; pref[i+1] = pref[i] + cur + a[i]; }
  while (q--) {
    int l, r; std::cin >> l >> r;
    std::cout << pref[r] - pref[l-1] << '\n'; 
  }
  return 0;
}
