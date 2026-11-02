#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n, m; std::cin >> n >> m;
        std::string p, q; std::cin >> p >> q;
        std::vector<int> cnt(26);
        for (char c : p) cnt[c - 'a']++;
        for (char c : q) cnt[c - 'a']--;
        for (char c : std::string("six")) cnt[c - 'a']--;
        bool ok = std::all_of(cnt.begin(), cnt.end(), [](int x) { return x == 0; });
        std::cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
