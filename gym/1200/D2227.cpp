#include <iostream>
#include <vector>
using namespace std; 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(2 * n);
        int x = -1, y = -1;
        for (int i = 0; i < 2 * n; ++i) {
            cin >> a[i];
            if (a[i] == 0) {
                if (x == -1)
                    x = i;
                else
                    y = i;
            }
        }

        auto expand = [&](int l, int r) {
            vector<char> seen(n + 1, false);
            int mex = 0;
            while (l >= 0 && r < 2 * n && a[l] == a[r]) {
                seen[a[l]] = true;
                while (mex <= n && seen[mex]) {
                    ++mex;
                }
                --l; ++r;
            }
            return mex;
        };

        int ans = 0;
        ans = max(ans, expand(x, x));
        ans = max(ans, expand(y, y));
        int l = (x + y) / 2;
        int r = (x + y + 1) / 2;
        ans = max(ans, expand(l, r));
        cout << ans << '\n';
    }
}