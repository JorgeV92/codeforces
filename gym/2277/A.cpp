#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> c(n + 1);
        for (int i = 0, x; i < n; i++) cin >> x, c[x]++;
        int ans = 0, sum = 0;
        for (int x = 0; x < n; x++) {
            sum += c[x];
            if (!c[x] || sum < k * (x + 1)) break;
            ans = x + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
