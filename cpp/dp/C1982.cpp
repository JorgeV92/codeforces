#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdint>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    auto jorgee = [&]() -> void {
        int T; cin >> T;
        while (T--) {
            int64_t n, l, r; cin >> n >> l >> r;
            vector<int64_t> a(n); for (int i = 0; i < n; i++) cin >>a[i];
            int ans = 0;
            int lo = 0;
            int64_t sum = 0;
            for (int hi = 0; hi < n; hi++) {
                sum += a[hi];
                while (lo <= hi && sum > r) {
                    sum -= a[lo++];
                }
                if (l <= sum && sum <= r) {
                    ans++;
                    sum = 0;
                    lo = hi + 1;
                }
            }
            cout << ans << '\n';
        }
    }; jorgee();
    return 0;   
}