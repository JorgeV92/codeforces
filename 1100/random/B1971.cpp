#include <iostream>
#include <vector>
#include <string>
#include <array>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        std::array<int, 26> cnt{};
        int dist = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            dist += (cnt[s[i]-'a']++ == 0);
            ans += dist;
        }
        std::cout << ans << '\n';
    }
    return 0;
}