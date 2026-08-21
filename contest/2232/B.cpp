#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    int n; std::cin >> n;
    std::vector<int64_t> a(n); for (auto& x : a) std::cin>>x;
    int64_t sum = 0;
    int64_t ans = 1e18;
    for (int i = 0; i < n; ++i) {
      sum += a[i];
      ans = std::min(ans, sum/(i+1));
      std::cout << ans <<  ' ';
    }
    std::cout << '\n';
  }
  return 0;
}
