#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n;
        std::vector<int> p(n+1);
        std::vector<int> pos(n+1);
        for (int i = 1; i <= n; i++) {
            std::cin >> p[i];
            pos[p[i]] = i;
        }
        int mx = 0;
        int bad = 0;
        for (int i = 1; i <= n+1; i++) {
            int score = (i-1)-bad;
            mx = std::max(mx, score);
            if (i <= n) {
                if (pos[i] < i) {
                    bad++;
                }
            }
        }
        std::cout << mx << '\n';
    }
    return 0;
}   