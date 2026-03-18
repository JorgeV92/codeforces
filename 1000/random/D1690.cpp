#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> W(n+1);
        for (int i = 1; i <= n; i++) {
            W[i] = W[i-1] + (s[i-1] == 'W');
        }
        int ans = INT_MAX;
        for (int i = k; i <= n; i++) {
            ans = min(ans, W[i] - W[i-k]);
        }
        cout << ans << '\n';
    }
    return 0;
}