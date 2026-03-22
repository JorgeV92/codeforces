#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int tt;
    std::cin >> tt;
    while (tt--) {
        int64_t n, x;
        std::cin >> n >> x;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        sort(a.begin(), a.end());
        int64_t sum = 0;
        int64_t ans = 0;
        for (int i = 0; i < n; i++) {
            if (i && sum + 1LL * i * (a[i] - a[i-1]) > x) {
                ans = a[i-1] + (x-sum) / i;
                break;
            }
            if (i) {
                sum += 1LL * i * (a[i] - a[i-1]);
            }
            if (i == n-1) {
                ans = a[i] + (x-sum) / n;
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}