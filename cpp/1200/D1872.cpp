#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    auto jorgee = [&]() -> void {
        int T; cin >> T;
        while (T--) {
            int64_t n, x, y; cin >> n >> x >> y;
            auto sum_first = [&](int64_t m) {
                return m * (m + 1) / 2;
            };
            auto sum_largest = [&](int64_t n, int64_t cnt) {
                return cnt* (2 * n - cnt + 1) / 2;
            };
            int64_t l = std::lcm(x, y);
            int64_t plus = n/x - n/l;
            int64_t minus = n/y-n/l;
            cout << sum_largest(n,plus) - sum_first(minus) << "\n";
        }
    }; jorgee();
    return 0;
}