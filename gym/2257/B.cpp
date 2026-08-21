#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<ll> A(n), B(m);
        for (int i = 0; i < n; ++i) cin >> A[i];
        for (int i = 0; i < m; ++i) cin >> B[i];
        ll a1 = A[0] + n-1;
        ll b1 = B[0] + m-1;
        if (a1 >= b1) {
            cout << 1 << '\n';
        }  else {
            cout << 2 << '\n';
        }
    }
    return 0;
}