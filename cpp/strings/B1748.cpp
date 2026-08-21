#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin>>T;
  while (T--) {
    int n; std::cin>>n;
    std::string s; std::cin>>s;
    std::vector<int>A(n); for (int i = 0; i < n; ++i) { A[i] = s[i]-'0'; }
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
      int cnt[10]{};
      int mx = 0, d = 0;
      for (int j = i; j < std::min(n, i+100); ++j) {
        if (!cnt[A[j]]) d++;
        mx = std::max(mx, ++cnt[A[j]]);
        ans += (mx <= d);
      }
    }
    std::cout << ans << '\n';
  }
  return 0; 
}
