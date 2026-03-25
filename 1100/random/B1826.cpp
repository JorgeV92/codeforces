#include <iostream>
#include <vector>
#include <numeric>
int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        int n; std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        int ans = 0;
        for (int i = 0; i < n ; i++) {
            ans = std::gcd(ans, a[i] - a[n-i-1]);
        }
        std::cout << ans << '\n';
    }
    return 0;   
}