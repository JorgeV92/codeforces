#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
typedef __int128 lll;
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        ll n, k; std::cin >> n >> k;
        std::vector<ll> sum0(n), D(n);
        std::vector<int> type(n);
        ll lo = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            ll a, b, c; std::cin >> a >> b >> c;
            sum0[i] = a + b + c;
            lo = std::min(lo, sum0[i]);
            if (a > b || b > c) type[i] = 1;
            else if (a == b && b == c) type[i] =  2;
            else { type[i] = 1; D[i] = std::min(b-a, c-b) + 1; }
        }
        auto cost = [&](ll S) -> lll {
            lll total = 0;
            for (int i = 0; i < n; i++) {
                if (S <= sum0[i]) continue;
                if (type[i] == 2) return (lll)k+1;
                total += (lll)(S - sum0[i]) + (type[i] == 1 ? 2 * (lll)D[i] : 0);
                if (total > k) return total;
            }
            return total;
        };
        ll hi = lo + k;
        while (lo < hi) {
            ll mid = lo + (hi - lo + 1) / 2;
            if (cost(mid) <= k) lo = mid; else hi = mid-1;
        }
        std::cout << lo << '\n';
    }

    return 0;
}