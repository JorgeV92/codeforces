#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using i64 = long long;
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n, m; std::cin >> n >> m;
  std::vector<i64> a(n); for (auto& x : a)std::cin>>x;
  std::vector<i64> d(n+1);
  auto add = [&](int l, int r, i64 x) {
    d[l-1] += x;
    d[r] -= x;
  };
  while (m--) {
    int l, r; i64 x;
    std::cin >> l >> r >> x;
    if (l<=r) add(l,r,x);
    else {
      add(l,n,x); add(1,r,x);
    }
  }
  i64 cur = 0;
  for (int i = 0; i < n; i++) {
    cur += d[i];
    std::cout << a[i] + cur << " \n"[i+1==n];
  }
  return 0;
}
