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
        int n ; cin >> n;
        vector<int64_t> A(n); for (int64_t& x : A) cin >> x;
        auto B = A;
        {
            for (int i = n-1; i > 0; i--) {
                B[i-1] = min(B[i-1], B[i]);
            }
        }
        int64_t tot = accumulate(A.begin(), A.end(), 0LL);
        int64_t nomove = accumulate(B.begin(), B.end(), 0LL);
        int64_t ans = tot - nomove;
        int64_t best = 0;
        vector<int64_t> F(n+1);
        for (int i = 0; i < n; i++) {
            F[B[i]]++;
            best = max(best, F[A[i]]);
        }   
        cout << (ans + max(0LL, best-1)) << '\n';
    }
    return 0;    
}