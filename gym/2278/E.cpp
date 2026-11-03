#include <algorithm>
#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n;
        std::vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            if (i % 2 == 0) a[i] = -a[i];
        }
        std::sort(a.begin(), a.end());
        long long ans = 0;
        for (int i = 0; i < n; i++) ans += (i < (n + 1) / 2 ? -a[i] : a[i]);
        std::cout << ans << '\n';
    }
    return 0;
}
