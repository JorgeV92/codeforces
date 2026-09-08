#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
using ll = long long;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        ll x, y; cin >> x >> y;
        ll S = x + y;
        ll a = 0;
        bool sm = false; 
        for (int b = 30; b >= 0; --b) {
            bool xb = (x >> b) & 1LL;
            bool sb = (S >> b) & 1LL;
            if (sm) {
                if (sb) {
                    a |= (1LL << b);
                }
            } else {
                if (xb && sb) {
                    a |= (1LL << b);
                } else if (xb && !sb) {
                    sm = true;
                }
            }
        }
        cout << S << ' ' << x-a << '\n';
    }
    return 0;
}