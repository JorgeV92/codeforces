#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdint>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string t; cin >> t;
        vector<bool> r(n+1);
        int64_t ans = 0;
        for (int k = 1;  k <= n; ++k) {
            for (int j = k; j <= n; j += k) {
                if (t[j-1] == '1') break;
                if (!r[j]) {
                    r[j] = true;
                    ans+=k;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;   
}