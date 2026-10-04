#include <iostream>
#include <vector>
#include <cstdint>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int64_t fact[11];
    auto countPerms = [&](const std::string& s) {
        int cnt[26] = {0};
        for (char c : s) cnt[c-'a']++;
        int64_t res = fact[s.size()];
        for (int k = 0; k < 26; k++) res /= fact[cnt[k]];
        return res;
    };
    fact[0] = 1;
    for (int i = 1; i <= 10; i++) fact[i] = fact[i-1] * i;
    int T; std:: cin >> T;
    while (T--) {
        int n;
        std::string s;
        std::cin >> n >> s;
        std::string best = s;
        int64_t bestCnt = countPerms(s);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; j++) {
                std::string cur = s;
                cur[i] = s[j];
                int64_t c = countPerms(cur);
                if (c < bestCnt) {
                    bestCnt = c;
                    best = cur;
                }
            }
        }
        std::cout << best << '\n';
    }
    
    return 0;
}