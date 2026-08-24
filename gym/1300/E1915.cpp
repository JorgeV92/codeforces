#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
        set<ll> seen{0};
        ll pref = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                pref += a[i];
            } else {
                pref -= a[i];
            }
            if (seen.find(pref) != seen.end()) {
                cout << "YES\n";
                goto end;
            }
            seen.insert(pref);
        }
        cout << "NO\n";
        end:;
    }
    return 0;
}