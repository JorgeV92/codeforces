#include <iostream>
#include <vector>
#include <algorithm>
using i64 = long long;
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n, x; std::cin >> n >> x;
  std::vector<int> a(n); for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::sort(a.begin(), a.end());
  int l = 0, r = n-1, ans = 0;
  while (l <= r) {
    if (a[l] + a[r] <= x) l++;
    r--;
    ans++;
  }
  std::cout << ans << '\n';
  return 0;
}
