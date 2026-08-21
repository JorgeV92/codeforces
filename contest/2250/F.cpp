#include <iostream>
#include <vector>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    int n, x; std::cin >> n >> x;
    bool power_of_two = (n & (n-1))  == 0;
    if (!power_of_two || (n == 2 && x != 0)) {
      std::cout << -1 << '\n';
      continue;
    }
    std::vector<int> p(n);
    if (x == 0) {
      for (int i = 0; i < n; ++i) {
        p[i] = i;
      }
    } else {
      std::vector<int> odd, even;
      odd.reserve(n/2); even.reserve(n/2);
      int cnt = 0;
      for (int v = 0; v < n; ++v) {
        int u = v ^ x;
        if (v > u) continue;
        if (cnt < n / 4) {
          odd.push_back(v);
          odd.push_back(u);
        } else {
          even.push_back(v);
          even.push_back(u);
        }
        cnt++;
      }
      for (int i = 0; i < n/2; ++i) {
        p[2*i] = even[i];
        p[2*i+1] = odd[i];
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int val = p[i] ^ p[j];
        if ((i&1) && (j&1)) {
          val ^= x;
        }
        std::cout << val << ' ';
      }
      std::cout << '\n';
    }
  }
  return 0;
}
