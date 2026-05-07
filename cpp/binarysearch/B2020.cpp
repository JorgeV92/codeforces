#include <iostream>
#include <vector>
#include <algorithm>

using i64 = long long;
using i128 = __int128_t;

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(nullptr);
    auto jorgee = [&]() -> void {
        int T; std::cin >> T;
        while (T--) {
            i64 k; std::cin >> k;
            i64 lo = 0, hi = 2000000000LL;
            while (lo < hi) {
                i64 mid = lo + (hi - lo) / 2;
                if ((i128)mid * (mid + 1) >= k) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            std::cout << k + lo << '\n';
        }
    }; jorgee();
    return 0;
}