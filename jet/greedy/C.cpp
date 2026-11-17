#include <iostream>
#include <vector>
#include <algorithm>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n; std::cin >>  n;
  std::vector<int> opp(n);
  std::vector<char> is_opp(2*n+1);
  for (auto& x : opp) {
    std::cin >> x;
    is_opp[x] = 1;
  }
  std::vector<int> me;
  for (int x=1; x <= 2*n; x++) {
    if (!is_opp[x]) me.push_back(x);
  }
  std::sort(opp.begin(), opp.end());
  int i = 0, j =0, ans = 0;
  while (i < n && j < n) {
    if (me[j] > opp[i]) {
      ans++;
      i++;
    } 
    j++;
  }
  std::cout << ans << '\n';

  return 0;
}
