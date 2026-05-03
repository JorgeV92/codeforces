#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    auto jorgee = [&]() -> void {
        int n; std::cin >> n;
        std::vector<int> p(n+2);
        for (int i = 1; i < n; i++) {
            int x; std::cin >> x;
            p[i+1] = x;
        }
        std::vector<int> color(n+2);
        for (int i = 1; i <= n; i++) {
            std::cin >> color[i];
        }
        int ans = 1;
        for (int i = 2; i <= n; i++) {
            if (color[i] != color[p[i]]) ans++;
        }
        std::cout << ans << '\n';
    }; jorgee();
    return 0;   
}