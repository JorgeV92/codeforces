#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n;
        std::cin >> n;
        std::vector<std::string> g(n);
        for (int i = 0; i < n; i++) {
            std::cin >> g[i];
        }
        std::vector<int> p(n);
        std::iota(p.begin(), p.end(), 0);
        std::sort(p.begin(), p.end(), [&](int x, int y) {
            if (g[x][y] == '1') return x < y;
            else return x > y;
        });
        for (auto i : p) {
            std::cout << i + 1 << " ";
        }
        std::cout << '\n';
    }
    return 0;
}