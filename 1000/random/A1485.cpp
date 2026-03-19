#include <iostream>
#include <vector>

void solve() {
    int a, b;
    std::cin >> a >> b;
    int ans = 1e9;
    for (int i = 0; i < 30; i++) {
        if (b + i == 1) continue;
        int res = i;
        int x = a;
        while (x > 0) {
            x /= b + i;
            res++;
        }
        ans = std::min(ans, res);
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    
    return 0;
}