#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    auto jorgee = [&]() -> void {
        int T; cin >> T;
        while (T--) {
            int n, m; cin >> n >> m;
            vector<int64_t> cnt(m+1,0);
            for (int i = 0; i < n; i++) {
                int x; cin >> x;
                cnt[x%m]++;
            }
            int64_t ans = 0;
            if (cnt[0] > 0) {
                ans++;
            }
            for (int r = 1; r < (m+1) / 2; ++r) {
                int64_t a = cnt[r];
                int64_t b = cnt[m-r];
                if (a == 0 && b == 0) {
                    continue;
                }

                if (a == 0 || b == 0) {
                    ans += max(a, b);
                } else {
                    int d = abs(a-b);
                    ans += 1 + max(0, d-1);
                }

            }
            if (m%2==0 && cnt[m/2]>0) {
                ans++;
            }
            cout << ans << "\n";
        }
    }; jorgee();
    return 0;
}