#include <iostream>
#include <vector>
#include <cstdint>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int n; std::cin >> n;
    int64_t x = 0, ans = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        int64_t y; std::cin >> y;
        x = std::max(y, x + y);
        ans = std::max(ans, x);
    }
    std::cout << ans << '\n';
    return 0;
}