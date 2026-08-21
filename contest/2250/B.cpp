#include <iostream>
#include <vector>
#include <string>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    int N, K; std::cin >> N >> K;
    int R = N - K;
    if (R == 1) {
      std::cout << -1 << '\n';
      continue;
    }
    int ones = (N+1)/2;
    int zeros = N / 2;
    int r_o = (R + 1) / 2;
    int r_z = R / 2;

    int ex_o = ones - r_o;
    int ex_z = zeros - r_z;
    
    std::string ans{};
    ans.reserve(N);

    for (int i = 0; i < R; i++) {
      char c = (i % 2 == 0 ? '1' : '0');
      int l = 1;
      if (i == 0) l += ex_o;
      if (i == 1) l += ex_z;
      ans.append(l, c);
    }
    std::cout << ans << '\n';
  }
  return 0;
}
