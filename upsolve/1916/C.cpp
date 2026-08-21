#include <iostream>
#include <vector>
using i64 = long long;
void solve() {
  int n; std::cin  >> n;
  i64 sum = 0;
  int odd = 0;
  for (int i = 0; i < n; ++i) {
    i64 x; std::cin >> x;
    sum += x;
    odd += x % 2;
    i64 loss = odd/3;
    if (odd % 3 == 1) ++loss;
    if (i == 0) loss =0;
    std::cout << sum-loss << ' ';
  }
  std::cout << '\n';
}
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
