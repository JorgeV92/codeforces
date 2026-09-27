#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n, q; std::cin >> n >> q;
        int cnt = 0;
        std::vector<int> a(n); for (int& x : a) {std::cin >> x; cnt += (__builtin_parity(x)==0) ; }
        std::cout << cnt << ' ';
        while (q--) {
            int p, x; std::cin >> p >> x; --p;
            cnt -= (__builtin_parity(a[p]) == 0);
            a[p] = x;
            cnt += (__builtin_parity(x) == 0);
            std::cout << cnt << ' ';
        }
        std::cout << '\n';

    }
    return 0;   
}