#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdint>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<int64_t> pref(n+1);
        for (int i = 0; i< n; i++) {
            pref[i+1] = pref[i] + a[i];
        }
        int64_t ans = 0;
        for (int x = 0; x<= k; x++) {
            int y = k - x;
            ans = max(ans, pref[n -y] - pref[2*x]);
        }
        cout << ans << "\n";
    }
    return 0;
}
