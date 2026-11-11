#include <iostream>
#include <vector>
using i64 = long long;
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n, q; std::cin >> n >> q;
  std::vector<i64> a(n); for (auto& x : a) std::cin >>x;
  std::vector<i64> pref(n+1); for (int i = 0; i < n; i++) pref[i+1] = pref[i] ^ a[i];
  while (q--) {
    int l, r; std::cin >> l >> r;
    std::cout << (pref[r] ^ pref[l-1]) << '\n';
  }
  return 0;
}
