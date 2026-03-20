#include <iostream>
#include <vector>
#include <cstdint>

void solve() {
    int64_t n;
    std::cin >> n;

    auto fair = [&](int64_t x) {
        int64_t tmp = x;
        while (tmp > 0) {
            int d = tmp % 10;
            if (d != 0 && x % d != 0) {
                return false;
            }
            tmp /= 10;
        }   
        return true;
    };

    while (!fair(n)) {
        n++;
    }
    std::cout << n << '\n';
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}