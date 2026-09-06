#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n); for (int& i : a) cin >> i;
        for (int i = 0; i < n; i++) {
            if (a[i] == -1) a[i] = 1;
            if (a[i] == 1) break;
        }
        for (int i = n-1; i >= 0; i--) {
            if (a[i] == -1) a[i] = 1;
            if (a[i] == 1) break;
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] == -1) a[i] = 0;
        }
        for (int x : a) cout << x << ' ';
        cout << '\n';
    }
}