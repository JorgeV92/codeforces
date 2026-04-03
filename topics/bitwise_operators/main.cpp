#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int x = 7;
    for (int i = 31; i >= 0; i--) {
        if (x & (1 << i)) std::cout << "1";
        else std::cout << "0";
    }
    std::cout << "\n";

    x = 5328; // 00000000000000000001010011010000
    std::cout << __builtin_clz(x) << "\n"; // 19
    std::cout << __builtin_ctz(x) << "\n"; // 4
    std::cout << __builtin_popcount(x) << "\n"; // 5
    std::cout << __builtin_parity(x) << "\n"; // 1

    x = 0;
    x |= (1<<1);
    x |= (1<<3);
    x |= (1<<4);
    x |= (1<<8);
    std::cout << __builtin_popcount(x) << "\n"; // 4
    for (int i = 0; i < 32; i++) {
        if (x & (1 << i)) 
            std::cout << i << ' ';
    }
    std::cout << '\n';

    x = (1<<1)|(1<<3)|(1<<4)|(1<<8);
    int y = (1<<3)|(1<<6)|(1<<8)|(1<<9);
    int z = x|y;
    std::cout << __builtin_popcount(z) << "\n"; // 6 

    return 0;
}