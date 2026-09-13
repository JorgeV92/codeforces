#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
int main() {    
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int t; std::cin >> t;
    while (t--) {
        int n; std::cin >> n;
        std::vector<int> a(n); for (int& i : a) std::cin >> i;
        int64_t sum = 0, seg = 0, ans = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            sum +=a[i];
            mx = std::max(mx, sum);
            if (sum - mx < seg) {
                seg = sum - mx;
                ans = mx;
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}