#include <iostream>
#include <vector>
using ll = long long;
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int t; std::cin >> t; 
    while (t--) {
        int n; std::cin >> n;
        ll odd = 0, zero = 0, two = 0;
        for (int i = 0; i < n; ++i) {
            ll x; std::cin >> x;
            if (x % 2) {
                odd++;
            } else if (x % 4 == 0) {
                zero++;
            } else {
                ++two;
            }
        }
        std::cout << std::max({odd, two, zero}) << '\n';
    }
    return 0;
}