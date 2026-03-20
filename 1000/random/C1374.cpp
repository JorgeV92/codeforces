#include <iostream>
#include <vector>
#include <stack>
#include <string>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int tt;
    std::cin >> tt;

    while (tt--) {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;

        std::string stk;
        
        auto match = [&](char l, char r) -> bool {
            return (l == '(' && r == ')');
        };

        auto other = [&]() {
            int mn = 0, b = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == '(') {
                    b++;
                } else {
                    --b;
                }
                mn = std::min(mn, b);
            }
            std::cout << -mn << '\n';
        };

        int ans = 0;
        for (char c : s) {
            if (c == '(') 
                stk.push_back(c);
            else if (stk.empty() || !match(stk.back(), c)) {
                ans++;
            } else {
                stk.pop_back();
            }
        }   
        std::cout << ans << '\n';
    }
    return 0;
}