#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i64 = long long;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int i = 0 ; i < n; ++i) cin >> a[i];
        int mx = *max_element(a.begin(), a.end());
        
        auto can = [&](int m) {
            for (int i = 0; i < n; ++i) {
                int tt = m;
                i64 cost = 0;
                bool valid = false;
                for (int j = i; j < n; j++) {
                    if (a[j] >= tt) {
                        valid = true;
                        break;
                    }
                    if (j==n-1) break;
                    cost += tt - a[j];
                    if (cost > k) break;
                    --tt;
                }
                if (valid && cost <= k) 
                    return true;
            }
            return false;
        };

        int lo = mx;
        int hi = mx + k;
        i64 ans = mx;
        while (lo <= hi) {
            int mid = lo + (hi-lo) / 2;
            if (can(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid -1;
            }
        }
        cout << ans << '\n';
    }
    return 0;  
}