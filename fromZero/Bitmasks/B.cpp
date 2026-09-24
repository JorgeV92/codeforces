#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int a, b; std::cin >> a >> b;
        std::cout << (a ^ b) << '\n';
    }
    return 0;
}