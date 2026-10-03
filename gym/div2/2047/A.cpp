#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n;
        int sum = 0, h = 0;
        for (int i = 0; i < n; ++i) {
            int a; std::cin >> a;
            sum += a;
            int r = (int)std::round(std::sqrt((double)sum));
            if (r * r == sum && r % 2 == 1) h++;
        }
        std::cout << h << '\n';
    }
    return 0;   
}