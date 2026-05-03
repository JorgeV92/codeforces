#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    auto jorgee = [&]() -> void {
        int T; cin >> T;
        while (T--) {
            int n, m; cin >> n >> m;
            vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
            vector<bool> can(n-1);
            for (int i = 0; i < m; i++) {
                int p; cin >> p;
                p--;
                can[p] = true;
            }
            int l = 0;
            while (l < n) {
                int r = l;
                while (r < n-1 && can[r]) r++;
                sort(a.begin() + l, a.begin() + r + 1);
                l = r + 1;
            }
            if (is_sorted(a.begin(), a.end())) {
                cout << "YES\n"; 
            } else {
                cout << "NO\n";
            }
        }
    }; jorgee();
    return 0;
}