#include <iostream>
#include <vector>
#include <cstdint>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n;
        std::vector<int> a(n), b(n); 
        for (int& x : a) std::cin >> x;
        for (int& x : b) std::cin >> x;
        int64_t mx = 0;
        int mn = INT_MIN;
        for (int i = 0; i < n; ++i) {
            mx += std::max(a[i], b[i]);
            mn = std::max(mn, std::min(a[i], b[i]));
        }
        std::cout << mx + mn << '\n';
    }
    return 0;   
}