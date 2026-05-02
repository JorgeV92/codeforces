#include <iostream>
#include <vector>
#include <cstdint>
#include <string>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        std::string s; std::cin >> s;
        int f = 1;
        for (char c : s) {
            int d = c - '0';
            int x = d * d;
            int nf = f << d;
            if (x < 10) {
                nf |= f << x;
            }
            nf |= (nf >> 9);
            nf &= (1 << 9) - 1;
            f = nf;
        }
        if (f & 1) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }

    }
    return 0;
}