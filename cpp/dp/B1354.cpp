#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    auto jorgee = [&]() -> void {
        int T; cin >> T;
        while (T--) {
            string s; cin >> s;
            int n = s.size();
            vector<int> cnt(4,0);
            int ans = n+1;
            int l = 0;
            for (int r = 0; r < n; r++) {
                cnt[s[r]-'0']++;
                while (cnt[1] > 0 && cnt[2] > 0 && cnt[3] > 0) {
                    ans = min(ans, r - l + 1);
                    cnt[s[l++]-'0']--;
                }
            }
            if (ans == n+1) {
                cout << 0 << '\n';
            } else {
                cout << ans << '\n';
            }
        }
    }; jorgee();
    return 0;
}