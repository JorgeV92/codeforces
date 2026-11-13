#include <iostream>
#include <vector>
using i64 = long long;
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int h, w, q; std::cin >> h >> w >> q; 
  std::vector<std::vector<i64>> pref(h+1,std::vector<i64>(w+1));
  for (int i=1; i<=h; i++) {
    for (int j=1; j<=w; j++) {
      i64 x; std::cin >> x;
      pref[i][j] = x + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
    }
  }
  while (q--) {
    int r1,c1,r2,c2; std::cin >>r1>>c1>>r2>>c2;
    i64 ans = pref[r2][c2]-pref[r1-1][c2]-pref[r2][c1-1]+pref[r1-1][c1-1];
    std::cout<<ans<<'\n';
  }
  return 0;
}
