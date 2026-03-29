#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n;
        std::string s, t; 
        std::cin >> s >> t;
        if (s == t) {
            std::cout << "YES\n";
            continue;
        }
        auto get_L = [](const std::string& str, int len) {
            int l = 0;
            for (int i = 0; i < len-1; i++) {
                if (str[i] == '(' && str[i+1] == ')') {
                    l++;
                }
            }
            return l;
        };
        auto get_C = [](const std::string& str, int len) {
            std::vector<int> match(len);
            std::vector<int> st(len); 
            int top = 0;
            for (int i = 0; i < len; i++) {
                if (str[i] == '(') {
                    st[top++] = i;
                } else {
                    match[st[--top]] = i;
                }
            }
            int c = 0, l = 0, r = len-1;
            while (l < r) {
                if (match[l]==r) {
                    c++; l++; r--;
                } else {
                    break;
                }
            }
            return c;
        };
        int L_s = get_L(s, n);
        int L_t = get_L(t, n);
        int C_s = get_C(s, n);
        int C_t = get_C(t, n);
        if (L_s == L_t && C_s == C_t) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}