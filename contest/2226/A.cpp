#include <iostream>
#include <vector>
#include <algorithm>
const int mod = 676767677;
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n; std::vector<int> a(n); for (int& x : a) std::cin >> x;
        int ans = 0; 
        for (int x : a) {
            if (x > 1) ans += x;
        }
        if (a.back() == 1) ans += 1;
        std::cout << ans << '\n';
    }
    return 0;   
}
