#include <iostream>
#include <string>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int x, y, z; std::cin >> x >> y >> z;
        int r, s, p;
        if (x >= y) {
            r = x - y; s = 0; p = z + 2 * y;
        } else if (y >= z) {
            r = x + 2 * z; s = y - z; p = 0;
        } else {
            r = 0; s = y + 2 * x; p = z - x;
        }
        std::cout << std::string(r, 'R') << std::string(s, 'S') << std::string(p, 'P') << '\n';
    }
    return 0;
}
