#include <iostream>
#include <vector>
#include <string>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int t; std::cin >> t;
    while (t--)  {
        int n; std::cin >> n;
        std::string s; std::cin >> s;
        if (s[0] == '1') {
            int z = 0;
            for (char c : s) if (c=='0') z++;
            std::cout << z << '\n';
            continue;
        }
        int ii = 0;
        while (ii < n && s[ii] == '0') ii++;
        if (ii == n) {
            std::cout << 0 << '\n';
            continue;
        }
        int zz = 0;
        for (int i = ii; i < n; ++i) {
            if (s[i] == '0') zz++;
        }
        int l = 0;
        int ans = zz;
        for (int i = ii; i < n; ++i) {
            if (s[i] == '1') l++;
            else zz--;
            ans = std::min(ans, l + zz);
        }
        std::cout << ans << '\n';
    }
    return 0;
}