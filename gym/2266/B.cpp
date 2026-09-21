#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int t; std::cin >> t;
    while (t--) {
        ll a, b, c; std:: cin >> a >> b >> c;
        std::cout << std::max(std::llabs(a-b), std::llabs(a+c-b)) << '\n';
    }
    return 0;
}