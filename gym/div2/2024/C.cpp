#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n;
        std::vector<std::pair<ll,ll>> p(n);
        for (auto& [x, y] : p) std::cin >> x >> y;
        std::sort(p.begin(), p.end(), [](const auto& a, const auto& b) {
            return a.first + a.second < b.first + b.second; 
        });
        for (int i = 0; i < n; ++i) std::cout << p[i].first << ' ' << p[i].second << " \n"[i+1==n];
    }
    return 0;
}