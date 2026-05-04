#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    auto jorgee = [&]() -> void {
        int T; cin >> T;
        while (T--) {
            int n, k; cin >> n >> k;
            vector<int> c(n);
            vector<int> lst(k, -1);
            vector<vector<int>> f(k);
            for (int i = 0 ; i < n; i++) {
                cin >> c[i];
                c[i]--;
                f[c[i]].push_back(i - lst[c[i]] - 1);
                lst[c[i]] = i;
            }
            int ans = n;
            for (int i = 0; i < k; i++) {
                f[i].push_back(n-lst[i]-1);
                sort(f[i].begin(), f[i].end(), greater());
                int res = f[i][0] / 2;
                if (f[i].size() > 1) {
                    res = max(res, f[i][1]);
                }
                ans = min(ans, res);
            }
            cout << ans << '\n';
        }
    }; jorgee();
    return 0;
}