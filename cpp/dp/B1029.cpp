#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int64_t> a(n); for (int i = 0; i < n; i++) std::cin >> a[i];
    int64_t cur = 1;
    int64_t ans = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] <= 2 * a[i-1]) {
            cur++;
        } else {
            ans = std::max(ans, cur);
            cur = 1;
        }
    }
    ans = std::max(ans, cur);
    std::cout << ans << "\n";
    return 0;
}