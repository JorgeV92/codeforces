#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int mx = 0;
            int mn = 0;
            for (int j = i + 1; j < n; j++) {
                if (a[j] > a[i]) mx++;
                else if (a[j] < a[i]) mn++;
            }
            res[i] = max(mx, mn);
        }
        for (int i = 0; i < n; i++) {
            cout << res[i] << " \n"[i==n-1];
        }
    }
    return 0;
}