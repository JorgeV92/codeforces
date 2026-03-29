#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n;
        for (int i = n; i >= 1; i--) {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }
    return 0;
}   