#include <iostream>
#include <vector>
#include <cstdint>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int64_t a, b; std::cin >> a >> b;
        std::cout << std::max(0LL, std::min(a, 2*a-b)) << '\n';
    }
    return 0;
}