#include <iostream>
#include <string>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int n, m; std::cin >> n >> m;
    std::string s; std::cin >> s;
    std::vector<std::string> perms {
        "abc", "acb", "bac", "bca", "cab","cba"
    };
    std::vector<std::vector<int>> pref(6, std::vector<int>(n+1, 0));

    for (int k = 0; k < 6; ++k) {
        for (int i = 0; i < n; ++i) {
            char c = perms[k][i%3];
            pref[k][i+1] = pref[k][i] + (s[i] != c);
        }
    }
    
    while (m--) {
        int l, r;
        std::cin >> l >> r;
        int ans = INT_MAX;
        for (int k = 0; k < 6; ++k) {
            int x = pref[k][r] - pref[k][l-1];
            ans = std::min(ans, x);
        }
        std::cout << ans << '\n';
    }
    return 0;
}