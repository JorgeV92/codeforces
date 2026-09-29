#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<bool> isL(n + 2, false), isR(n + 2, false);
    int maxL = 1, minR = n;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        isL[l] = isR[r] = true;
        maxL = max(maxL, l);
        minR = min(minR, r);
    }

    vector<int> p(n + 1, -1);
    vector<bool> used(n, false);
    auto fillRest = [&]() {
        int v = 0;
        for (int i = 1; i <= n; i++) {
            if (p[i] == -1) {
                while (used[v]) v++;
                p[i] = v;
                used[v] = true;
            }
        }
    };

    if (maxL <= minR) {
        p[maxL] = 0; used[0] = true;
        fillRest();
    } else {
        int x = -1, dir = 0;
        for (int i = 1; i <= n; i++) {
            if (!isR[i])      { x = i; dir = 1;  break; }
            else if (!isL[i]) { x = i; dir = -1; break; }
        }
        if (x != -1) {
            p[x] = 0; used[0] = true;
            int y = x + dir;
            if (1 <= y && y <= n) { p[y] = 1; used[1] = true; }
            fillRest();
        } else {
            p[1] = 0; p[2] = 2; p[3] = 1;
            used[0] = used[1] = used[2] = true;
            fillRest();
        }
    }
    for (int i = 1; i <= n; i++)
        cout << p[i] << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}