#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int a, b; std::cin >> a >> b;
        int ans{};
        if (b <= a && (a -b)%2 == 0) ans = a;
        else if (b <= a + 1 && (a - b) % 2 != 0) ans = a + 1;
        else ans = -1;
        std::cout << ans << '\n';
    }
    return 0;
}