#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int t; std::cin >> t;
    while (t--) {
        int n; std::cin >> n;
        std::vector<int> a(3); for (int& x : a) std::cin >> x;
        int cnt = 0;
        int a1 = n-a[0];
        int a2 = n-a[1];
        int a3 = n-a[2];
        std::cout << std::max({a1,a2,a3}) << '\n';
    }
    return 0;   
}