#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdint>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) {
        return a[i] > a[j];
    });
    vector<int> x(n+1);
    int64_t res = 0;
    for (int i = 0; i < n; i++) {
        x[p[i]+1] = (i % 2 == 0 ? 1 : -1) * (i/2+1);
        res += 2LL * abs(x[p[i]+1] ) * a[p[i]];
    }
    cout << res << '\n';
    for (int i = 0; i <= n; i++) {
        cout << x[i] << " \n"[i==n];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}