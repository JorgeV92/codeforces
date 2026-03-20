#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int tt;
    std::cin >> tt;    
    while (tt--) {  
        int64_t a, b;
        std::cin >> a >> b;
        if (a < b)
            std::swap(a,b);
        if (a % b) {
            std::cout << -1 << '\n';
        } else {
            a /= b;
            if (a & (a-1)) {
                std::cout << -1 << '\n';
            } else {
                std::cout << ((int)std::log2(a) + 2) / 3 << '\n';
            }
        }

    }
    return 0;
}