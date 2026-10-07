#include <iostream>
#include <vector>
#include <string>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n;
        std::string s; std::cin >> s;
        int cnt[256]{0};
        for (char c : s) cnt[c]++;
        int ans = 0;
        for (char c : {'A', 'B', 'C', 'D'}) 
            ans += std::min(cnt[c], n);
        std::cout << ans << '\n';

    }
    return 0;
}