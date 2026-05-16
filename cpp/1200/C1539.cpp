#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdint>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int64_t n, k, x; cin >> n >> k >> x;
    vector<int64_t> a(n); for (int i= 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    int64_t ans = 1;
    vector<int64_t> v;
    for (int i = 0; i < n-1; ++i) {
        int64_t d = a[i+1] - a[i];
        if (d > x) {
            ans++;
            v.push_back((d-1)/x);
        }
    }
    sort(v.begin(), v.end());
    for (int64_t x : v) {
        if (k >= x) {
            k -= x;
            ans--;
        } else {
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}