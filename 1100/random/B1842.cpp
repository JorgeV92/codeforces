#include <iostream>
#include <vector>
#include <cstdint>

void solve() {
    int64_t n, x;
    std::cin >> n >> x;
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        int u = 0;
        bool ok = true;
        for (int i = 0 ;i < n; i++) {
            int a;
            std::cin >> a;
            if ((a & x) != a) {
                ok = false;
            }
            if (ok) {
                u |= a;
            }
        }
        ans |= u;
    }
    if (ans == x) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
} 