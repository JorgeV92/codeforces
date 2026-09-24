#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int n; std::cin >> n;
    int64_t d; std::cin >> d;
    std::vector<std::pair<int64_t, int64_t>> f(n);
    for (auto& [m, s] : f) std::cin >> m >> s;
    std::sort(f.begin(), f.end());
    int64_t sum = 0, ans =0 ;
    int l = 0;
    for (int r = 0; r < n; ++r) {
        sum += f[r].second;
        while (f[r].first - f[l].first >= d) 
            sum -= f[l++].second;
        ans = std::max(ans, sum);
    }
    std::cout << ans << '\n';
    return 0;
}