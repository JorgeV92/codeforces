#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n; int64_t m; std::cin >> n >> m;
        std::vector<std::pair<int64_t, int64_t>> f(n);
        for (auto& p : f) std::cin >> p.first;
        for (auto& p : f) std::cin >> p.second;
        std::sort(f.begin(), f.end());
        int64_t ans = 0;
        for (int i = 0; i < n; ++i) {
            int64_t v = f[i].first, cnt = f[i].second;
            ans = std::max(ans, v * std::min(cnt, m/v));
            if (i + 1 < n && f[i+1].first == v+1) {
                int64_t c2 = f[i+1].second;
                
                auto eval = [&](int64_t y) -> int64_t {
                    if (y < 0) return (int64_t)-1;
                    int64_t x = std::min(cnt, std::max((int64_t)0, m-(v+1)*y) / v);
                    return (v+1) * y + v * x;
                };
                int64_t y2 = std::min(c2, m/(v+1));
                int64_t y1 = std::min(c2, std::max((int64_t)0, m-v*cnt)/(v+1));
                int64_t y0 = y2 - ((y2-m) % v+v) % v;
                ans = std::max({ans, eval(y1), eval(y2), eval(y0)});
            }
        }
        std::cout << ans << '\n';
    }
    return 0;   
}