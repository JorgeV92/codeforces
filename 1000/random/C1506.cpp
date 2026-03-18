#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    int ans = 0;
    for (int i = 0; i< n; i++) {
        for (int j = i; j < n; j++) {
            string c = a.substr(i, j- i + 1);
            if (b.find(c) != string::npos) {
                ans = max(ans, (int)c.size());
            }
        }
    }
    cout << m + n - 2 * ans << '\n';
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