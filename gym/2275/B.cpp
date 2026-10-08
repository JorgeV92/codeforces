#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n;
        std::string s; std::cin >> s;
        std::vector<char> used(n+1);
        std::stack<int> st;
        for (int i = 1; i <= n; ++i) {
            if (s[i-1] == '1') {
                st.push(i);
            } else if (s[i-1] == '2') {
                if (!st.empty()) {
                    used[st.top()] = 1;
                    st.pop();
                } else {
                    used[i] = 1;
                }
            } else {
                used[i] = 1;
            }
        }
        std::vector<int> ans;
        for (int i = 1; i <= n; ++i) {
            if (!used[i]) ans.push_back(i);
        }
        std::cout << ans.size() << '\n';
        for (int i = 0; i < (int)ans.size(); i++) {
            std::cout << ans[i] << ' ';
        }
        std::cout << '\n';
    }
    return 0;   
}