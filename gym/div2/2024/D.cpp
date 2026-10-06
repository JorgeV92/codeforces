#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
const ll INF = (ll)4e18;
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n;
        std::vector<ll> a(n+1), S(n+1);
        std::vector<int> b(n+1);
        for (int i = 1; i <= n; i++) { std::cin >> a[i]; S[i] = S[i-1] + a[i]; }
        std::vector<std::vector<int>> byB(n+2);
        for (int i = 1; i <= n; ++i) { std::cin >> b[i]; byB[b[i]].push_back(i); }
        int sz= 1; while (sz < n+2) sz <<= 1;
        std::vector<ll> seg(2*sz, INF);
        auto upd = [&](int p, ll v) {
            p += sz; seg[p] = v;
            for (p >>= 1; p; p >>= 1) seg[p] = std::min(seg[2*p], seg[2*p+1]);
        };
        auto rmq = [&](int l, int r) {
            ll res= INF;
            for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
                if (l&1) res = std::min(res, seg[l++]);
                if (!(r&1)) res = std::min(res, seg[r--]);
            }
            return res;
        };
        std::vector<ll> g(n+2, INF);
        g[1] = 0; upd(1, 0);
        for (int t = 2; t <= n; t++) {
            ll best = INF;
            for (int x : byB[t]) {
                if (x <= t-1)
                    best =  std::min(best, a[x] + rmq(x, t-1));
            }
            if (best < INF) { g[t] = best; upd(t, best); }
        }
        ll ans = 0;
        for (int m = 1; m <= n; m++) {
            if (g[m] < INF) ans = std::max(ans, S[m] - g[m]);
        }
        std::cout << ans << '\n';

    }
    return 0;
}