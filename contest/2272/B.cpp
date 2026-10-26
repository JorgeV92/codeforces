#include <algorithm>
#include <iostream>
#include <string>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n;
        std::string s[2]; std::cin >> s[0] >> s[1];
        int total[2] = {}, matching[2] = {};
        for (int row = 0; row < 2; row++) {
            for (int i = 0; i < n; i++) {
                if (s[row][i] != 'f') continue;
                int j = i;
                while (j + 1 < n && s[row][j + 1] == 'f') j++;
                total[row] += j - i + 1;
                matching[row] += (j - i + 1) / 2;
                i = j;
            }
        }
        int unmatched[2];
        for (int row = 0; row < 2; row++) unmatched[row] = total[row] - 2 * matching[row];
        int ans = n * 2;
        for (int vertical = 0; vertical <= std::min(total[0], total[1]); vertical++) {
            int removed = 0;
            for (int row = 0; row < 2; row++) {
                removed += std::max(unmatched[row] - vertical, (total[row] - vertical) % 2);
            }
            ans = std::min(ans, removed);
        }
        std::cout << ans << '\n';
    }
    return 0;
}
