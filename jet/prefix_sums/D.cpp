#include <iostream>
#include <vector>
using i64 = long long;
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n, m; std::cin >> n >> m;
  std::vector<i64> a(n); for (auto& x : a) std::cin >> x;
  std::vector<i64> d(n+1);
  while (m--) {
    int l, r; i64 x; 
    std::cin >> l >> r >> x;
    d[l-1] += x;
    d[r] -= x;
  }
  i64 sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += d[i];
    std::cout << a[i] + sum << " \n"[i+1==n];
  }
  return 0;
}
