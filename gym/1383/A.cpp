#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n;
        std::string a, b; std::cin >> a >> b;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i]) ok = false;
        }
        if (!ok) {
            std::cout << "-1\n";
            continue;
        }
        int ans = 0;
        for (char c = 'a'; c <= 't'; c++) {
            char mn = 't' + 1;
            for (int i = 0; i < n; ++i) {
                if (a[i] == c && b[i] != c) 
                    mn = std::min(mn, b[i]);
            }
            if (mn == 't' + 1) continue;
            ans++;
            for (int i = 0; i < n; ++i) 
                if (a[i] == c && a[i] != b[i]) a[i] = mn;
        }
        std::cout << ans << '\n';

    }
    return 0;
}