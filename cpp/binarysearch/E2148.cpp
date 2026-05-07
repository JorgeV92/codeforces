#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;

int main() {
    auto jorgee = [&]() -> void {
        int n, k; cin >> n >> k;
        vector<int> cnt(n+1);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int x : a) {
            cnt[x]++;
        }
        for (auto& x : cnt) {
            if (x % k != 0) {
                cout << 0 << '\n';
                return;
            }
            x /= k;
        }
        int64_t ans = 0;
        for (int i = 0, j = 0; i < n; i++) {
            cnt[a[i]]--;
            while (cnt[a[i]] < 0) {
                cnt[a[j]]++; 
                j++;
            }
            ans += i - j + 1;
        }
        cout << ans << '\n';

    }; 
    int T; cin >> T;
    while (T--) {
        jorgee();
    }
    return 0;
}