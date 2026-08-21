#include <iostream>
#include <vector>
#include <algorithm>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    std::vector<int> v(3);
    std::cin >> v[0] >> v[1] >> v[2];
    std::sort(v.begin(), v.end());
    int l = v[1] - v[0];
    int r = v[2] - v[1];
    std::cout << std::min(l, r) << '\n';
  }
  return 0;
}
