#include <iostream>
#include <cstdint>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int n; std::cin >> n;
    int64_t ans = 0;
    int neg = 0;
    int zeros = 0;
    for (int i = 0; i < n; ++i) {
        int64_t x; std::cin >> x;
        if (x > 0) ans += x-1;
        else if (x < 0) { ans += -1 - x; neg++; }
        else {ans += 1; zeros++; }
    }
    if (neg % 2 == 1 && zeros == 0) ans += 2;
    std::cout << ans << '\n';
    return 0;
}