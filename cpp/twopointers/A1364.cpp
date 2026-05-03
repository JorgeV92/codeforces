#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdint>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    auto CS = [&]() {
        int T; cin >> T;
        while (T--) {
            int n, x; cin >> n >> x;
            vector<int> a(n); for (int& x : a) cin >> x;
            int64_t S = accumulate(a.begin(), a.end(), 0LL);
            if (S % x != 0) {
                cout << n << '\n';
                continue;
            }
            int l = -1;
            for (int i= 0; i < n; i++) {
                if (a[i] % x != 0) {
                    l = i;
                    break;
                }
            }
            if (l == -1) {
                cout << -1 << '\n';
                continue;
            }
            int r = -1;
            for (int i = n-1; i >= 0; i--) {
                if (a[i] % x != 0) {
                    r = i;
                    break;
                }
            }
            cout << max(n-l-1, r) << "\n";
        }
    }; CS();
    return 0;
}