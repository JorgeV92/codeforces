#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n, k; std::cin >> n >> k;
        if (k == 0) {
            std::cout << "0\n";
            continue;
        }
        int ans = 1;
        k -= n;
        for (int s = n-1; s >= 1 && k > 0; s--) {
            for (int cnt = 0; cnt < 2 && k > 0; cnt++) {
                k -= s;
                ans++;
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}