#include <iostream>
#include <numeric>
#include <vector>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    int n; std::cin >> n; 
    std::vector<int> a(n); for (int& x : a) std::cin >> x;
    int sum = std::accumulate(a.begin(), a.end(), 0);
    std::cout << (sum % 4 == 0 ? "YES" : "NO") << '\n'; 
  }
  return 0;
}
