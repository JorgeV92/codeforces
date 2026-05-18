#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> c(n); for (auto& x : c) cin>>x;
        int64_t oo = 0;
        vector<int64_t> up;
        for (auto x : c) {
            if (x==1) oo++;
            else up.push_back(x);
        }
        int64_t ans = 0;
        if (up.empty()) {
            ans = 0;
        } else if (up.size() == 1) {
            int64_t cnt = up[0];
            ans = cnt + min(oo,cnt/2);
            if (ans<3) ans = 0;
        } else {
            int64_t t = 0;
            int64_t cap = 0;
            for (auto x : up) {
                t += x;
                cap += x / 2 - 1;
            }
            ans = t + min(oo, cap);
        }
        cout << ans << '\n';
    }
    return 0;
}