#include <iostream>
#include <vector>
#include <cstdint>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int t; std::cin >> t;
    while (t--) {
        int64_t n; std::cin >> n;
        int64_t p = 1;
        while ((p << 1) <= n) p <<= 1;
        std::cout << p-1 << '\n';
    }
    return 0;
}