#include <iostream>
#include <vector>
#include <cstdint>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int n; int64_t x; std::cin >> n >> x;
    std::vector<int64_t> a(n); for (int i =0 ; i < n; ++i) std::cin >> a[i];
    int64_t sum = 0;
    int l = 0;
    int ans = 0;
    for (int r = 0; r < n; r++) {
        sum += a[r];
        while (sum > x && l <= r) {
            sum -=a[l++];
        }
        if (sum == x) ans++;
    }
    std::cout << ans << '\n';
    return 0;
}