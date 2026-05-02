#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N; vector<int64_t> A(N); for (int64_t& x : A) cin >> x;
        auto B = A;
        {
            sort(B.begin(), B.end());
        }
        int64_t ans = 0;
        int64_t offset = 0;
        for (int i = 0; i < N; i++) {
            offset += B[i] * i;
        }
        for (int i = 0; i < N; i++) {
            offset -= A[i] * i;
        }
        for (int i = 0; i < N; i++) {
            int64_t t = i - (lower_bound(B.begin(), B.end(), A[i]) - B.begin());
            ans = max(ans, t);
        }
        cout << (ans + offset) << '\n';

    }
    return 0;
}