#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n); for (int& x : a) cin >> x;
        if (is_sorted(a.begin(), a.end())) {
            cout << 0 << '\n';
            continue;
        }
        if (a[n-2]  > a[n-1] || a[n-1] < 0) {
            cout << -1 << '\n';
            continue;
        }
        cout << n-2 << '\n';
        for (int i = 0; i < n-2; ++i) {
            cout << i+1 << ' ' << n-1 << ' ' <<  n << '\n';
        }
    }
    return 0;
}