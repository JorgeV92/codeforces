#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int t; std::cin >> t;
    while (t--) {
        int n; std::cin >> n;
        std::vector<int64_t> b(n);
        for (int i = 0; i < n; ++i) {
            int64_t a; std::cin >> a;
            b[i] = a - (i+1);
        }
        std::sort(b.begin(), b.end());
        int ans = 1;
        int cur = 1;
        for (int i = 1; i < n; i++) {
            if (b[i] == b[i-1]) continue;
            if (b[i] == b[i-1] + 1) cur++;
            else cur = 1;
            ans = std::max(ans, cur);
        }
        std::cout << ans << '\n';
    }
    return 0;   
}