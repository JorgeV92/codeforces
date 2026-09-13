#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std; 
using ll = long long;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n); for (int& x : a) cin >> x;
    priority_queue<ll> pq; 
    ll sum = 0;
    ll ans = LLONG_MIN;
    for (int i = 0; i < n; ++i) {
        if (pq.size() == m-1) {
            ans = max(ans, 1LL*m*a[i]-sum);
        }
        pq.push(a[i]);
        sum += a[i];
        if (pq.size()> m-1) {
            sum -= pq.top();
            pq.pop();
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}