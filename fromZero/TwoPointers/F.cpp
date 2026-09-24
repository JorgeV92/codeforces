#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int n; int64_t t; std::cin >> n >> t;
    std::vector<int> a(n); for (int& x : a) std::cin >> x;
    int64_t sum = 0;
    int ans = 0, l = 0;
    for (int r = 0 ; r < n; r++) {
        sum += a[r];
        while (sum > t) sum -= a[l++];
        ans = std::max(ans, r - l + 1);
    }
    std::cout << ans << '\n';
    return 0;
}