#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <ranges>
#include <cassert>
using namespace std;
using i64 = long long;
namespace rgs = std::ranges;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    auto cs = [&]() -> void {
        int64_t p, q; cin >> p >> q;
        i64 E = p + 2 * q;
        for (int n = 2; 2*n*(n-1) <= E; n++) {
            int m = E + n;
            if (m % (2*n-1)) {
                continue;
            }
            m /= 2 * n-1;
            assert(n <= m);
            if (q <= n * m-m) {
                std::cout << n-1 << " " << m-1 << "\n";
                return;
            }
        }
        std::cout << -1 << '\n';
    };
    int T; cin >> T;
    while (T--) {
        cs();
    }
    return 0;
}