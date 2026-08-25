#include <iostream>
#include <vector>
#include <string>
#include <tuple>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, c, q; cin >> n >> c >> q;
        string s; cin >> s;
        vector<tuple<ll,ll,ll>> op;
        ll len = n;
        while (c--) {
            ll l, r; cin >> l >> r;
            op.push_back(make_tuple(len, l, r));
            len += r - l +1;
        }
        while (q--) {
            ll k; cin >> k;
            for (auto it = op.rbegin(); it != op.rend(); ++it) {
                auto [old, l ,r] = *it;
                if (k > old) {
                    k = l + (k - old) - 1;
                }
            }
            cout << s[k-1] << '\n';
        }
    }
}