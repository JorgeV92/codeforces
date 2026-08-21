#include <iostream>
#include <vector>
#include <string>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n;
        std::string s; std::cin >> s;
        int n0 =0, n1=0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') ++n0;
            else ++n1;
        }
        int delta = n0 - n1;
        if (std::abs(delta) > 2) {
            std::cout << -1 << '\n';
            continue;
        }
        int  L= 1;
        int L0 = (s[0] == '0');
        int L1 = (s[0] == '1');
        for (int i = 1; i < n; ++i) {
            if (s[i] != s[i-1]) {
                ++L;
                if (s[i] == '0') L0++;
                else L1++;
            }
        }
        int deltaL = L0-L1;
        int del = n - L;
        int extra = std::max(0, std::abs(delta-deltaL) - 1);
        std::cout << del + extra << '\n';
    }
    return 0;
}