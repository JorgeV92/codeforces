#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n);
        for (ll &v : a)
            cin >> v;
        vector<ll> x(n);
        for (int i = 0; i < n; ++i) {
            x[i] = a[i] - k * i;
        }
        vector<ll> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + x[i];
        }
        vector<ll> ans(n, 0);
        for (int i = 1; i < n - 1; ++i) {
            ll q = a[i - 1] - k * i;
            int lo = i + 1;
            int hi = n;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (x[mid] > q) lo = mid + 1;
                else hi = mid;
            }
            int p = lo;
            ll cnt = p - (i + 1);
            ll sum = pref[p] - pref[i + 1];
            ans[i] = sum - cnt * q;
        }
        for (ll v : ans) cout << v << ' ';
        cout << '\n';
    }
}