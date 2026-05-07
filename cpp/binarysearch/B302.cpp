#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdint>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    auto jorgee = [&]() -> void {
        int n, m; cin >> n >> m;
        vector<int64_t> s(n);
        for (int i = 0; i < n; i++) {
            int64_t c, t; cin >> c >> t;
            s[i] = (c*t);
        }
        vector<int64_t> pref(n+1);
        for (int i = 0; i < n; i++) {
            pref[i+1] = pref[i] + s[i];
        }
        for (int i = 0; i < m; i++) {
            int v; cin >> v;
            int j = lower_bound(pref.begin(), pref.end(), v) - pref.begin();
            cout << j << "\n";
        }
    }; jorgee();
    return 0;
}