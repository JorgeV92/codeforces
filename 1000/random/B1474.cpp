#include <iostream>
#include <vector>

void solve() {
    int d;
    std::cin >> d;
    std::vector<int> p;
    for (int i = d+1; ; i++) {
        int t = 1;
        for (int j = 2; j*j <= i; j++) {
            if ( i % j == 0) {
                t = 0;
                break;
            }
        }
        if (t) {
            p.push_back(i);
            break;
        }
    }
    for (int i = p.back() + d; ; i++) {
        int t = 1;
        for (int j = 2.; j*j <= i; j++) {
            if (i % j == 0) {
                t = 0;
                break;
            }
        }
        if (t) {
            p.push_back(i);
            break;
        } 
    }
    std::cout << std::min(1LL * p[0] * p[1], 1ll * p[0] * p[0] * p[0]) << '\n';
}
    
int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}