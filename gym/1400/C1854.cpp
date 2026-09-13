#include <iostream>
#include <vector>
#include <string>
using namespace std;
void solve() {
    string s; cin >> s;
    int m; cin >> m;
    string l, r; cin >> l >> r;
    int p = 0;
    for (int i = 0; i < m; ++i) {
        int q = p;
        for (char x = l[i]; x <= r[i]; x++) {
            if (s.find(x, p) == -1) {
                cout << "YES\n";
                return;
            }
            q = max(q, int(s.find(x, p) ) + 1);
        }
        p = q;
    }
    cout << "NO\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}