#include <iostream>
#include <vector>
#include <string>
void solve() {
    int n; std::cin >> n;
    std::string x; std::cin >> x;
    int idx = 0;
    if (n % 2 != 0) {
        if (x[0] == 'b') {
            std::cout << "NO\n";
            return;
        }
        idx = 1;
    }
    for (int i = idx; i < n; i += 2) {
        if (x[i] == 'a' && x[i+1] == 'a') {
            std::cout << "NO\n";
            return;
        }
        if (x[i] == 'b' && x[i+1] == 'b') {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
}
int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        solve();
    }   
    return 0;
}