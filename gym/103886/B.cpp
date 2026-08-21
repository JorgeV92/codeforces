#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int H, K, n; cin >> H >> K >> n;
    vector<int> x(n), y(n); for (int i = 0; i < n; ++i) { cin >> x[i] >> y[i]; }
    double ans=0.0;
    for (int cx = 0; cx <= H; ++cx) {
        for (int cy = 0;  cy <= K; ++cy) {
            double mn = min({cx, H-cx, cy, K-cy});
            for (int i = 0; i < n; ++i) {
                double dx = cx - x[i], dy = cy - y[i];
                double dist = sqrt(dx * dx + dy * dy);
                mn = min(mn, dist);
            }
            ans = max(ans, mn);
        }
    }
    cout << fixed << setprecision(10) << ans << '\n';
    return 0;   
}