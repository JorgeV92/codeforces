#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        int zeros = 0;
        for (int &x : a) {
            cin >> x;
            if (x == 0)
                ++zeros;
        }
        if (zeros == 1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        string ans(n, 'C');
        if (zeros == 0) {
            cout << ans << '\n';
            continue;
        }
        int seen = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                if (seen == 0)
                    ans[i] = 'A';
                else if (seen == 1)
                    ans[i] = 'B';
                else
                    ans[i] = 'A';

                ++seen;
            }
        }
        cout << ans << '\n';
    }
}