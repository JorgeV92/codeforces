#include <iostream>
#include <vector>
bool is_prime(int x) {
    if (x < 2) return false;
    for (int d = 2; 1LL * d *d <= x; ++d) {
        if (x % d == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n;
        if (is_prime(n+1)) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
    return 0;  
}