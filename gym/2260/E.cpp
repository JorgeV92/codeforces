#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std; 
void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<int> pref(n+1, 0);
    for (int i = 0; i < n; ++i) {
        pref[i+1] = pref[i] + (s[i] == '1');
    } 
    vector<int> prefD(n+1, 0);
    for (int i = 0; i+1 < n; ++i) {
        prefD[i+1] = prefD[i] + (s[i] != s[i+1]);
    }
    while (q--) {
        int l,r; cin >> l >> r;
        l--; r--;
        int len = r - l  + 1;
        int ones = pref[r+1] - pref[l];
        int zeros = len - ones;
        int c = prefD[r] - prefD[l];
        if (s[r] != s[l]) c++;
        int d = c/2;
        int c00 = zeros - d;
        int c11 = ones - d;
        int lo = 0, hi = len;
        while (lo < hi) {
            int mid = lo + (hi-lo) / 2;
            int b = max(0, c00-mid) + max(0, c11-mid);
            if (d + b <= mid) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        int K = lo;
        cout << 4*K - len << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}