#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <ranges>
using i64 = long long;
namespace rgs = std::ranges;
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n;
        i64 m, k; std::cin >> m >> k;
        std::vector<i64> l(n), r(n);
        for (int i = 0; i < n; ++i) std::cin >> l[i] >> r[i];
        if (k == 0) {
            std::cout << r[n-1] + 1 << '\n';
            continue;
        }
        std::map<i64, i64> ev;
        for (int i = 0; i < n; ++i) {
            ev[l[i] - m] += 1;
            ev[r[i]+1-m] -= 1;
            ev[l[i]] -= 1;
            ev[r[i]+1] += 1;
        }
        std::vector<std::pair<i64,i64>> evs(ev.begin(), ev.end());
        i64 f = 0, sigma = 0, fmax = 0, ans = -1, prev = 0;
        for (int i = 0; i < (int)evs.size(); i++) {
            i64 p = evs[i].first;
            if (i > 0) f += sigma * (p - prev);
            fmax = std::max(fmax, f);
            sigma += evs[i].second;
            i64 q = (i + 1 < (int)evs.size()) ? evs[i+1].first : p;
            i64 L = q - p;
            i64 cand = -1;
            if (sigma == 1 && f <= k && k <= f + L) cand = p + (k-f);
            else if (sigma == -1 && f - L <= k && k <= f) cand = p + (f-k);
            else if (sigma == 0 && f == k) cand = q;
            if (cand != -1) ans = std::max(ans, cand);
            prev = p;
        }
        if (k > fmax) std::cout << -1 << '\n';
        else std::cout << ans << '\n';
    }
    return 0;
}