#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n;
        std::vector<int> cnt(101); 
        for (int i = 0; i < n; i++) {
            int x; std::cin >> x;
            cnt[x]++;
        }
        std::vector<std::pair<int,int>> vr;
        for (int v = 1; v <= 100; v++) {
            for (int r = 1; r <= cnt[v]; r++) {
                vr.emplace_back(r, v);
            }
        }
        std::sort(vr.begin(), vr.end(), [&](const auto& a, const auto& b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });
        for (int i = 0; i < n; ++i) std::cout << vr[i].second << ' ';
        std::cout << '\n';
    }
    return 0;
}