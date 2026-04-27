#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> A(N); for (int i = 0; i < N; i++) { cin >> A[i]; }
        int med;
        {
            assert(N&1);
            vector<int> vals = A;
            nth_element(vals.begin(), vals.begin() + (N/2), vals.end());
            med = vals[N/2];
        }
        vector<int> pref_lt(N+1, 0);
        vector<int> pref_le(N+1,0);
        for (int i = 0; i < N; i++) {
            pref_lt[i+1] = pref_lt[i] + (A[i] < med);
            pref_le[i+1] = pref_le[i] + (A[i] <= med);
        }
        vector<int> dp(N+1, -N-1);
        dp[0] = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j <= N; j += 2) {
                int cnt_lt = pref_lt[j] - pref_lt[i];
                int cnt_le = pref_le[j] - pref_le[i];
                int cnt_tot = j - i;
                assert(cnt_tot & 1);
                if (cnt_lt <= cnt_tot / 2 && cnt_tot / 2 < cnt_le) {
                    dp[j] = max(dp[j], dp[i]+ 1);
                }
            }
        }
        assert(dp[N] >= 1);
        cout << dp[N] << '\n';
    }
    return 0;
}