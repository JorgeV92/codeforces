#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdint>

using namespace std;

int64_t _gcd(int64_t a, int64_t b) {
    int64_t gcdcode = 1;
    while (b) {
        a %= b;
        swap(a, b);
    }
    gcdcode = a;
    return gcdcode;
}

int64_t _lcm(int64_t a, int64_t b) {
    if (a == 0 || b == 0) return 0;
    return (a / _gcd(a, b)) * b;
}

void solve() {
    int n;
    cin >> n;
    vector<int64_t> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<int64_t> g(n);
    for (int i = 1; i < n; i++) {
        g[i] = _gcd(a[i], a[i+1]);
    }

    vector<int64_t> L(n + 1);
    if (n > 1) {
        L[1] = g[1];
        for (int i = 2; i < n; i++) {
            L[i] = _lcm(g[i-1], g[i]);
        }
        L[n] = g[n-1];
    }

    vector<int64_t> u(n), v(n + 1);
    for (int i = 1; i < n; i++) {
        u[i] = L[i] / g[i];
        v[i+1] = L[i+1] / g[i];
    }

    vector<int64_t> U(n + 1, 1), V(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        if (i > 1) U[i] = u[i-1];
        if (i < n) V[i] = v[i+1];
    }
    vector<vector<int64_t>> C(n + 1);
    vector<int64_t> c(n + 1);
    for (int i = 1; i <= n; i++) {
        c[i] = a[i] / L[i];
        C[i].push_back(c[i]);

        int64_t K = b[i] / L[i];
        int64_t limit = min(K, 300LL); 
        for (int64_t x = 1; x <= limit; x++) {
            if (x == c[i]) continue;
            if (_gcd(x, U[i]) == 1 && _gcd(x, V[i]) == 1) {
                C[i].push_back(x);
            }
        }
    }
    vector<int> dp(C[1].size(), -1);
    for(size_t j = 0; j < C[1].size(); j++) {
        dp[j] = (C[1][j] != c[1] ? 1 : 0);
    }
    for (int i = 2; i <= n; i++) {
        vector<pair<int, int64_t>> prev;
        for(size_t k = 0; k < C[i-1].size(); k++) {
            if (dp[k] != -1) {
                prev.push_back({dp[k], C[i-1][k]});
            }
        }
        sort(prev.begin(), prev.end(), 
        [](const pair<int, int64_t>& x, const pair<int, int64_t>& y) {
            return x.first > y.first;
        });

        vector<int> next_dp(C[i].size(), -1);
        for (size_t j = 0; j < C[i].size(); j++) {
            int64_t x_i = C[i][j];
            int cost = (x_i != c[i] ? 1 : 0);
            int best = -1;
            
            for (const auto& p : prev) {
                if (_gcd(p.second, x_i) == 1) {
                    best = p.first + cost;
                    break;
                }
            }
            next_dp[j] = best;
        }
        dp = std::move(next_dp);
    }
    int ans = 0;
    for (int val : dp) {
        ans = max(ans, val);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}