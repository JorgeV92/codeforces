#include <iostream>
#include <vector>
#include <numeric>
using ll = long long;
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    ll a, b; std::cin >> a >> b;
    if (b % a == 0) {
      std::cout << b / a * b << '\n';
    } else {
      std::cout << std::lcm(a, b) << '\n';
    }
  }
  return 0;
}
