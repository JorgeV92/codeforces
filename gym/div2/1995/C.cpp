#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n;
        std::vector<int64_t> a(n); for (auto& x : a) std::cin >> x;
        int64_t ans = 0, prevCnt = 0;
        bool imp = false;
        for (int i = 1; i < n; i++) {
            int64_t x = a[i-1], y = a[i];
            if (y == 1) {
                if (x > 1) { imp = true; break; }
                prevCnt = 0;
                continue;
            }
            if (x== 1) { prevCnt = 0; continue; }
            int64_t k{};
            if (y >= x) {
                int64_t t = 0, v = x;
                while (v <= y/v) { v = v * v; t++; }
                k = std::max(0LL, prevCnt-t);
            } else {
                int64_t s =0, v = y;
                while (v < x) { v = v*v; s++; }
                k = prevCnt + s;
            }
            prevCnt = k;
            ans += k;
        }
        std::cout << (imp ? -1 : ans) << '\n';
    }
    return 0;
}