#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::vector<int> p(n);
        for (int& i : p) std::cin >> i;
        for (int i = 0; i < n; i++) {
            if (n==1) {
                std::cout << 1 << " ";
            } else {
                std::cout << 2 << " ";
            }
        }
        std::cout << "\n"
    }
    return 0;
}