#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdint>
#include <cstring>
using namespace std;
int in1[100050];
int in2[100050];
int sum1[100050];
int sum2[100050];
auto dotorya() -> int {
    int N, K, i, j;
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++) scanf("%d", &in1[i]);
    for (int i = 1; i <= N; i++) scanf("%d", &in2[i]);
    for (int i = 1; i <= N; i++) {
        sum1[i] = sum1[i-1] + (in1[i] * in2[i]);
        sum2[i] = sum2[i-2] + in1[i];
    }
    int64_t mx = 0;
    for (int i = 1; i <= N - k + 1; i++) {
        int32_t v = sum1[i-1] + (sum2[i-k+1] + sum2[i-1]) + (sum1[N] - sum1[i+k-1]);
        mx = max(mx, v);
    }
    printf("%lld\n", mx);
    return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> a(n), t(n);
    for (int i = 0; i < n; i++) cin >> a[i]; for (int i = 0; i < n; i++) cin >> t[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (t[i] == 1) ans += a[i];
    }
    vector<int> g(n); for (int i = 0; i < n; i++) if (t[i] == 0) g[i] = a[i];
    int up = accumulate(g.begin(), g.begin() + k, 0);
    int f = up;
    for (int i = k; i < n; i++) {
        up += g[i];
        up -= g[i-k];
        f = max(f, up);
    }
    cout << ans + f << '\n';
    return 0;
}