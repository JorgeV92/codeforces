#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

using pii = pair<int,int>;

pii get() {
    int k;
    cin >> k;
    int x1, x2;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        if (i == 0) x1 = x;
        if (i == k-1) x2 = x;
    }
    return {x1,  x2};
}

int64_t area(pii a, pii b, pii c) {
    return abs(
        1LL * (b.first - a.first) * (c.second - a.second) - 
        1LL * (b.second - a.second) * (c.first - a.first)
    );
}

void solve() {
    int w, h;
    cin >> w >> h;
    vector<vector<pii>> v(4);
    auto[x1, x2] = get();
    v[0] = {{x1, 0}, {x2, 0}};
    auto [x3, x4] = get();
    v[1] = {{x3, h}, {x4, h}};
    auto [y1, y2] = get();
    v[2] = {{0, y1}, {0, y2}};
    auto [y3, y4] = get();
    v[3] = {{w, y3}, {w, y4}};

    int64_t ans = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i != j) {
                for (int k = 0; k < 2; k++) {
                    ans = max(ans, area(v[i][0], v[i][1], v[j][k]));
                }
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}