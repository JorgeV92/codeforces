#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    auto jorgee = [&]() -> void {
        int T; cin >> T;
        while (T--) {
            int n; cin >> n;
            vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
            a.erase(unique(a.begin(), a.end()), a.end());
            if (a.size() == 1) {
                cout << 1 << '\n';
                continue;
            }
            int ans = 2;
            n = a.size();
            for (int i = 1; i < n-1; i++) {
                if (a[i-1] < a[i] && a[i] > a[i+1]) ans++;
                if (a[i-1] > a[i] && a[i] < a[i+1]) ans++;
            } 
            cout << ans << '\n';
        }
    }; jorgee();
    return 0;
}