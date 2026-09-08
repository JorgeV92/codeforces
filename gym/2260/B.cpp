#include <iostream>
#include <vector>
using namespace std; 
using ll = long long; 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int x, y; cin>>x>>y;
        ll k; cin >> k;
        ll d = y-x;
        ll sm = min(k, max(0LL, d-x+1));
        ll ans = 0;
        for (ll i = 0; i < sm; ++i) {
            ans += d % (x + i);
        }
        ans += (k - sm) * d;
        cout << ans << '\n';
    }
    return 0;
}