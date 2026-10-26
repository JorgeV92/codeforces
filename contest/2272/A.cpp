#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int calc(const vector<int> &a, int k) {
    int n = a.size(), mex = 0;
    vector<int> f, seen(n + 1);
    for (int x : a) {
        seen[x] = 1;
        while (seen[mex]) mex++;
        f.push_back(mex);
    }
    sort(f.rbegin(), f.rend());
    return f[k - 1];
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int best = calc(a, k), x = -1, y = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(a[i], a[j]);
            int cur = calc(a, k);
            swap(a[i], a[j]);
            if (cur > best) {
                best = cur;
                x = i + 1;
                y = j + 1;
            }
        }
    }

    if (x == -1) cout << -1 << '\n';
    else cout << x << ' ' << y << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
