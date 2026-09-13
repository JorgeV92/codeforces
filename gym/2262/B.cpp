#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;
struct BIT {
    int n;
    vector<ll> bit;
    BIT(int n) : n(n), bit(n+1, 0) {} 
    void add (int idx, ll val) {
        for (++idx; idx <= n; idx += idx & -idx) 
            bit[idx] += val;
    }
    ll sumPrefix(int idx) {
        ll res = 0;
        for (++idx; idx > 0; idx -= idx & -idx) 
            res += bit[idx];
        return res;
    }
    ll sum(int l, int r) {
        if (l > r) return 0;
        return sumPrefix(r) - (l ? sumPrefix(l-1) : 0);
    }
};
void solve() {
    int n; cin >> n;
    vector<ll> a(n); for (ll& x : a) cin >> x;
    vector<int> p(n); for (int& x : p) cin >> x, x--;
    BIT bit(n);
    set<int> s;
    vector<int> ans; 
    for (int i = n-1; i >= 0; --i) {
        int pos = p[i];
        s.insert(pos);
        bit.add(pos, a[pos]);
        auto it = s.find(pos);

        auto merge_right = [&]() {
            while (it != s.end() && it != s.begin()) {
                int r = *it;
                int l = *prev(it);
                ll sum = bit.sum(l, r-1);
                if (sum >= a[r]) {
                    ++it;
                    s.erase(prev(it));
                } else break;
            }
        };

        merge_right();

        if (it != s.end()) {
            ++it;
            merge_right();
        }

        ans.push_back((int)s.size() -1 );
    }
    reverse(ans.begin(), ans.end());

    for (int x : ans) cout << x << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}