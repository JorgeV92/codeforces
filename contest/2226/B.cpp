#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int T; std::cin >> T; 
    while (T--) {
        int n; std::cin >> n; std::vector<int> p(n); for (int& x : p) std::cin >> x;
        int64_t ans =0 ;
        for (int i = 0; i + 1 < n; i++) {
            int x = abs(p[i] - p[i+1]);
            int g = std::gcd(p[i], p[i+1]);
            if (x == g) {
                ans++;
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}