#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n; 
        vector<int> p(n); for (int i = 0; i < n; i++) cin >> p[i];
        int l = 0, r = n-1;
        int mn = 1, mx = n;
        pair<int,int> ans{-1,-1};
        while (l < r) {
            if (p[l] == mn) {
                mn++;
                l++;
            } else if (p[l] == mx) {
                mx--;
                l++;
            } else if (p[r] == mn) {
                mn++;
                r--;
            } else if (p[r] == mx) {
                mx--;
                r--;
            } else {
                ans = {l+1, r+1};
                break;
            }
        }
        if (ans == make_pair(-1,-1)) {
            cout << -1 << '\n';
        } else {
            cout << ans.first << ' ' << ans.second << '\n';
        }
    }
    return 0;   
}