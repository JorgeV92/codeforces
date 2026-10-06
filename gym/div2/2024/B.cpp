#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n; int64_t k; std::cin >> n >> k;
        std::vector<int64_t> a(n); for (auto& x : a) std::cin >> x;
        std::sort(a.begin(), a.end());
        int64_t lo = 1, hi = 1e9;
        while (lo < hi) {
            int64_t mid = (lo+hi) / 2, s = 0;
            for (auto x : a) { s += std::min(x, mid); if (s >= k) break; }
            if (s >= k) hi = mid; else lo = mid+1;
        }
        int64_t f = std::lower_bound(a.begin(), a.end(), lo) - a. begin();
        std::cout << k + f << '\n';
    }
    return 0;
}