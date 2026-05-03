#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    auto jorgee = [&]() -> void {
        int T; std::cin >> T;
        while (T--) {
            int n; std::cin >> n;
            std::vector<int> l(n), r(n);
            for (int i = 0; i < n; i++) {
                std::cin >> l[i] >> r[i];
                l[i]--;
            }
            for (int i = 0 ; i < n; i++) {
                int x = l[i];
                for (int j = 0; j < n; j++) {
                    if (l[i] == l[j] && r[j] < r[i]) {
                        x = std::max(x, r[j]);
                    }
                }
                std::cout << l[i]+1 << ' ' << r[i] << " " << x + 1 << '\n';
            }
        }
    }; jorgee();
    return 0;
}