#include <iostream>
#include <vector>
#include <cstdint>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int t; std::cin >> t;
    while (t--) {
        int n; std::cin >> n;
        std::vector<int64_t> a(n);  
        int64_t x = 0;
        for (auto& v : a) {std::cin >> v; x ^= v; }
        if (x == 0) { std::cout << "DRAW\n"; continue; }
        int k = 63 - __builtin_clzll(x);
        int64_t cnt = 0;
        for (auto v : a) if (v >> k & 1) cnt++;
        int64_t zeros = n - cnt;
        if (cnt % 4 == 3 && zeros % 2 == 0) std::cout << "LOSE\n";
        else std::cout << "WIN\n"; 
    }
    return 0;
}