#include <iostream>
#include <vector>
#include <string>
void no() {std::cout << -1 << '\n'; }
int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int T; std::cin >> T;
    while (T--) {
        int a, b; std::cin >> a >> b;
        std::string s; std::cin >> s;
        int N = s.size();
        bool bad = false;
        for (int i = 0; i < N/2; i++) {
            int j= N-i-1;
            if (s[i] != '?' && s[j] != '?') {
                if (s[i] != s[j]) {
                    bad = true;
                }
            } else if (s[i] == '?' && s[j] != '?') {
                s[i] = s[j];
            } else if (s[i] != '?' && s[j] == '?') {
                s[j] = s[i];
            }
        }
        if (bad) {
            no();
            continue;
        }
        int cnt0 = 0, cnt1 = 0;
        for (char c : s) {
            if (c == '0') cnt0++;
            else if (c == '1') cnt1++;
        }
        a -= cnt0; b-= cnt1;
        if (a < 0 || b < 0) {
            no(); continue;
        }
        for (int i = 0; i < N/2; i++) {
            int j = N-i-1;
            if (s[i] == '?' && s[j] == '?') {
                if (a >= 2) {
                    s[i] = s[j] = '0';
                    a -= 2;
                } else if (b >= 2) {
                    s[i] = s[j] = '1';
                    b -= 2;
                } else {
                    bad = true;
                    break;
                }
            }
        }
        if (bad) { no(); continue; }
        if (N % 2 == 1 && s[N/2] == '?') {
            if (a==1) {
                s[N/2] = '0';
                a--;
            } else if (b == 1) {
                s[N/2] = '1';
                b--;
            } else {
                bad = true;
            }
        }
        if (a != 0 || b != 0) bad = true;
        for (int i = 0; i < N/2; i++) {
            if (s[i] != s[N-i-1]) {
                bad = true;
            }
        }
        if (bad) {
            std::cout << -1 << '\n';
        } else {
            std::cout << s << '\n';
        }
    }
    return 0;
}