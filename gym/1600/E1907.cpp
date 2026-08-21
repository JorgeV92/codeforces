#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        ll n; cin >> n;
        ll ans = 1;
        while (n > 0) {
            int d= n % 10;
             n/=10;
             ll w = (d + 1LL) * (d + 2LL) / 2;
             ans *= w;
        }
        cout << ans << '\n';
    }
    return 0;
}