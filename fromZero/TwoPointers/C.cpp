#include <iostream>
#include <vector>
#include <cstdint>
#include <unordered_map>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int n; int64_t x; std::cin >> n >> x;
    std::vector<int64_t> a(n); for (auto& x : a) std::cin >> x;
    std::unordered_map<int64_t, int64_t> cnt;
    cnt.reserve(n*2);
    cnt[0] = 1;
    int64_t ans = 0, pref = 0;
    for (int i = 0; i < n; ++i) {
        pref += a[i];
        ans +=  cnt[pref-x];
        cnt[pref]++;
    }
    std::cout << ans << '\n';
    return 0;
}   