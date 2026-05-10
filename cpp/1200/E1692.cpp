#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T-- ){
        int n, s; cin >> n>> s;
        vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
        int sum = accumulate(a.begin(), a.end(), 0);
        if (sum < s) {
            cout << -1 << '\n';
            continue;
        }
        int l = 0;
        int ans = -1;
        int cur = 0;
        for (int r = 0; r < n; r++) {
            cur += a[r];
            while (cur > s) {
                cur -= a[l++];
            }
            if (cur == s) {
                ans = max(ans, r -l+ 1);
            }
        }

        if (ans == -1) {
            cout << -1 << '\n';
        } else {
            cout << n - ans << '\n';
        }
        
    }
    return 0;
}