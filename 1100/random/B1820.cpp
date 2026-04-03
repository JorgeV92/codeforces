#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdint>
int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int T; std::cin >> T;
    while (T--) {
        std::string s; std::cin >> s;
        int n = s.size();
        int cnt = std::count(s.begin(), s.end(), '0');
        if (!cnt) {
            std::cout << int64_t(n) * n << "\n";
            continue;
        }
        s = s + s;
        int64_t ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') { 
                int j = i;
                while (s[j] == '1') j++;
                int l = j - i + 1;
                ans = std::max(ans, 1LL * (l/2) * ((l+1)/2));
                i= j;
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}