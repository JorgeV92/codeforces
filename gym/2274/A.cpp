#include <iostream>
#include <vector>
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n;
        std::vector<i64> a(n); for (auto& x : a) std::cin >> x;
        i64 x = 0;
        for (int i = n-1; i >= 0; i--) x = 2*a[i] - x;
        std::cout << x/2 << '\n';
    }
    return 0;
}