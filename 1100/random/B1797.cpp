#include <iostream>
#include <vector>
#include <cstdint>
int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int T; std::cin >> T;
    while (T--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<std::vector<int>> a(n, std::vector<int>(n));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                std::cin>>a[i][j];
            }
        }
        int64_t cnt = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cnt += (a[i][j] != a[n-1-i][n-1-j]);
            }
        }
        cnt /= 2;
        if (k >= cnt && (n % 2 == 1 || (k-cnt) % 2 == 0)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}