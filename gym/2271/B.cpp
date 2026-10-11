#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n, k; std::cin >> n >> k;
        std::vector<int> cnt(n+1);
        for (int i = 0; i < n; i++) {
            int x; std::cin >> x;
            cnt[x]++;
        }
        for (int x = 0; x <= n; x++) {
            if (cnt[x] < 2 * k) {
                std::cout << (cnt[x] == 2 * k - 1 ? "YES" : "NO") << '\n';
                break;
            }
        }
    }
    return 0;
}