#include <iostream>
#include <vector>
using ll = long long;

ll rangeAnd(ll a, ll b) {
    int shift = 0;
    while (a != b) {
        a >>= 1;
        b >>= 1;
        ++shift;
    }
    return a << shift;
}

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int t; std::cin >> t;
    while (t--) {
        ll n, x; std::cin >> n >> x;
        if ((n & x) != x) {
            std::cout << -1 << '\n';
            continue;
        } 
        if (n == x) {
            std::cout << n << '\n';
            continue;
        }
        ll diff = n ^ x;
        int k = 0;
        for (int i = 0; i <= 60; ++i) {
            if (diff & (1LL << i))
                k = i;
        }
        
        ll m = ((n >> (k + 1)) + 1) << (k + 1);
        if (rangeAnd(n, m) == x)
            std::cout << m << '\n';
        else
            std::cout << -1 << '\n';
    }

    return 0;
}