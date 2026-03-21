#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
using namespace std;

void solve() {
    int64_t n, c, k;
    cin >> n >> c >> k;
    vector<int64_t> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0 ;i < n; i++) {
        if (a[i] > c) break;
        int64_t x = min(k, c - a[i]);
        k -= x;
        c += a[i] + x;
    }
    cout << c << '\n';
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