#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n, m;
        std::cin >> n >> m;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            sum += x;
        }
        if (n == 2 || m < n) {
            std::cout << -1 << "\n";
            continue;
        }
        std::cout << 2 * sum << "\n";
        for (int i = 0; i < n; i++) {
            std::cout << i + 1 << ' ' << (i+1) % n + 1 << '\n';
        }
    }
    return 0;
}