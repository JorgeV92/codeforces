#include <iostream>
#include <vector>
using namespace std; 
using ll = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> p(n); for (int& i : p) cin >> p[i];

    auto generate_subsets = [&]() -> void {

        auto recurse = [&](auto&& recurse, int idx, ll sum1, ll sum2) {
            if (idx == n) { return abs(sum1 - sum2); }
            return min(recurse(recurse, idx+1, sum1 + p[idx], sum2), recurse(recurse,idx+1, sum1, sum2 + p[idx]));
        };
        cout << recurse(recurse, 0, 0 , 0) << endl;
    };

    auto bitmasks = [&]() {
        ll ans = INT64_MAX;
        for (int mask = 0;  mask < (1 << n); mask++) {
            ll sum1 = 0, sum2 = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    sum1 += p[i];
                } else {
                    sum2 += p[i];
                }
            }
            ans = min(ans, abs(sum1-sum2));
        }
        cout << ans << endl;   
    };

    // generate_subsets();
    bitmasks();

    return 0;   
}