#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int x0, y0, R; std::cin >> x0 >> y0 >> R;
        std::cout << x0 << ' ' << y0 + R << '\n';
    }
    return 0;   
}