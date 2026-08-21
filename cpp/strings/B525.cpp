#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  std::string s; std::cin >> s;
  int n = s.size();
  int m; std::cin >> m;
  std::vector<int> a(m); for (int& x : a) std::cin>>x;
  std::vector<int> S(n); for (int ai : a) S[ai-1]++;
  int cur = 0;
  for (int i = 0; i*2<n; ++i) {
    cur += S[i];
    if (cur%2)
      std::swap(s[i], s[n-i-1]);
  }
  std::cout << s << '\n';
  return 0;
}
