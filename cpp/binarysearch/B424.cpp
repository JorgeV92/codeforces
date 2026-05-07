#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {    
    ios::sync_with_stdio(0); cin.tie(0);
    auto jorgee = [&]() -> void {
        int n, s; cin >> n >> s;
        vector<pair<double, int>> d;
        for (int i = 0 ; i < n; i++) {
            int x, y, k; cin >> x >> y >> k;;
            double dd = sqrt(1.0*x*x + 1.0*y*y);
            d.push_back({dd, k});
        }
        sort(d.begin(), d.end());
        double ans = -1.0;
        for (int i = 0; i < (int)d.size(); i++) {
            s += d[i].second;
            if (s >= 1000000) {
                ans = d[i].first;
                break;
            }
        }
        if (ans == -1.0) cout << -1 << "\n";
        else cout << fixed << setprecision(10) << ans << '\n';
        
    }; jorgee();
    return 0;       
}