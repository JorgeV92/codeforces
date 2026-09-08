#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
using ll = long long;
void solve() {
    int n; cin >> n;
    multiset<ll> b;
    for (int i = 0; i < n; ++i) {
        ll x; cin >> x;
        b.insert(x);
    }
    vector<ll> ans;
    ans.reserve(n);
    ll cur = 0;
    for (int i = 0; i < n; ++i) {
        auto it = b.lower_bound(1 - cur);
        if (it == b.end()) {
            cout << -1 << '\n';
            return;
        }
        cur += *it;
        ans.push_back(cur);
        b.erase(it);
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}