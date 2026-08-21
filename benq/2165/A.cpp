#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<ll> A(n); for (int i = 0; i < n; ++i) cin >> A[i];
        vector<int> by_val(n);
        iota(by_val.begin(), by_val.end(), 0);
        sort(by_val.begin(), by_val.end(), [&](auto a, auto b) { return A[a] < A[b]; });
        ll ans = (n-1) * A.at(by_val.front());
        int pairs = 0;
        vector<bool> active(n);
        for (int i = 1; i < n; ++i) {
            int x = by_val.at(i-1);
            if (active.at((x + n-1) % n)) ++pairs;
            if (active.at((x+1) % n)) ++pairs;
            active.at(x) = true;
            ans += (A.at(by_val.at(i)) - A.at(by_val.at(i-1))) * (n - 1 - pairs);
        }
        cout << ans << '\n';
    }
    return 0;
}