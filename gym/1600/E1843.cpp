#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        vector<pair<int,int>> seg(m);
        for (auto &[l,r] : seg) {
            cin >> l >> r;
        }
        int q; cin >> q;
        vector<int> when(n+1, q+1);
        for (int i = 1; i <= q; i++) {
            int x; cin >> x;
            when[x] = i;
        }

        auto check = [&](int k) {
            vector<int> pref(n+1, 0);
            for (int i = 1; i <= n; ++i) {
                pref[i] = pref[i-1] + (when[i] <= k);
            }
            for (auto [l, r] : seg) {
                int ones = pref[r] - pref[l-1];
                int len = r - l + 1;
                if (2*ones>len) {
                    return true;
                }
            }
            return false;
        };

        int lo = 1;
        int hi = q;
        int ans= -1;
        while (lo <= hi) {
            int mid = lo + (hi-lo) / 2;
            if (check(mid)) {
                ans = mid;
                hi = mid-1;
            } else {
                lo = mid + 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}