#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <climits>
#include <cstdint>
struct pp {
  int x, y;
};
auto rotate_90(pp p, pp h) -> pp {
  int dx = p.x - h.x;
  int dy = p.y - h.y;
  return pp{h.x-dy, h.y+dx};
}
auto dist2(pp a, pp b) -> int64_t {
  int64_t dx = a.x - b.x;
  int64_t dy = a.y - b.y;
  return dx * dx + dy * dy;
} 
auto is_squared(const std::array<pp, 4>& p) -> bool {
  std::vector<int64_t> d;
  for (int i = 0; i < 4; ++i) {
    for (int j = i + 1; j < 4; ++j) {
      d.push_back(dist2(p[i], p[j]));
    }
  }
  std::sort(d.begin(), d.end());
  return d[0] > 0 && d[0] == d[1] && d[1] == d[2] && d[2] == d[3] && d[4] == d[5] && d[4] == 2*d[0];
}
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n; std::cin >> n;
  while (n--) {
    std::array<std::array<pp, 4>, 4> pos;
    for (int i = 0; i < 4; ++i) {
      pp s, h;
      std::cin >> s.x >> s.y >> h.x >> h.y;
      pos[i][0] = s;
      for (int r = 1; r < 4; ++r) {
        pos[i][r] = rotate_90(pos[i][r-1], h);
      }
    }
    int ans = 1e9;
    for (int r0 = 0; r0 < 4; ++r0) {
      for (int r1 = 0; r1 < 4; ++r1) {
        for (int r2 = 0; r2 < 4; ++r2) {
          for (int r3 = 0; r3 < 4; ++r3) {
            std::array<pp, 4> chosen {
              pos[0][r0],
              pos[1][r1],
              pos[2][r2],
              pos[3][r3]
            };
            if (is_squared(chosen)) {
              int m = r0 + r1 + r2 + r3;
              ans = std::min(ans,m);
            }
          }
        }
      }
    }
    if (ans == 1e9) {
      std::cout << -1 << '\n';
    } else {
      std::cout << ans << '\n';
    }
  }
  
  return 0; 
}
