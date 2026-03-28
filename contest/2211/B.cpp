#include <iostream>
#include <vector>
#include <cstdint>

const int64_t mod = 676767677;

int64_t numberOfDivisors(int64_t num) {
    int64_t total = 1;
    for (int i= 2; (int64_t)i*i <= num; i++) {
        if (num % i ==0) {
            int e = 0;
            do {
                e++;
                num /= i;
            } while (num%i==0);
            total *= e + 1;
        }
    }
    if (num > 1) {
        total *= 2;
    }
    return total;
}

void solve() {
    int64_t x, y;
    std::cin >> x >> y;
    int64_t s = abs(x-y);
    int64_t mn = numberOfDivisors(s) % mod;
    std::cout << mn << '\n';
    if (x >= y) {
        for (int i = 0; i < y; i++) {std::cout << "-1 ";}
        for (int i = 0; i < x; i++) {std::cout << "1 ";}
    } else {
        for (int i = 0; i < x; i++) {std::cout << "1 ";}
        for (int i = 0; i < y; i++) {std::cout << "-1 ";}
    }
    std::cout << '\n';
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