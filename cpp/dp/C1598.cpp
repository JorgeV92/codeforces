#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <numeric>
#include <map>

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    auto jorgee = [&]() -> void {
        int T; std::cin>> T;
        while (T--) {
            int n; std::cin >> n;
            std::vector<int64_t> a(n); for (int i = 0 ;i < n; i++) std::cin>>a[i];
            int64_t sum = accumulate(a.begin(), a.end(), 0LL);
            int mean = sum/n;
            if ((2*sum) % n != 0) {
                std::cout << 0 << "\n";
                continue;
            }
            int t = 2 * sum/n;
            std::map<int,int> mp;
            int64_t ans = 0;
            for (int x : a) {
                int tmp = t - x;
                ans += mp[tmp];
                mp[x]++;
            }
            std::cout << ans << '\n';
        }
    }; jorgee();
    return 0;
}