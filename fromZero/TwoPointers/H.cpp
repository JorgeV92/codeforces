#include <iostream>
#include <vector>
#include <cstdint>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int64_t> a(n); for (auto& x : a) std::cin >> x;
    std::vector<int64_t> cnt(n);
    cnt[0] = 1;
    int64_t pref = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        pref += a[i];
        int rem = (int)(((pref % n) + n) % n);
        ans += cnt[rem];
        cnt[rem]++;
    }
    std::cout << ans << '\n';

    return 0;
}