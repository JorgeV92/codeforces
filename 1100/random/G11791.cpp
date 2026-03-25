#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        int n, c;
        std::cin >> n >> c;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            a[i] += i + 1;
        }
        std::sort(a.begin(), a.end());
        int ans = 0;
        for (auto x : a) {
            if (x <= c) {
                ans++;
                c -= x; 
            }
        }
        std::cout << ans << '\n';
    }
}