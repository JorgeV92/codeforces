#include <iostream>
#include <vector>
#include <cstdint>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> a(n); for (int i = 0; i < n; i++) { cin >> a[i]; }
        vector<pair<int64_t,int>> pref(n);
        pref[0]={0,0};
        for (int i = 0; i < n-1; i++) {
            pref[i+1] = {pref[i].first + a[i], i+1};
        }
        sort(pref.begin(), pref.end());
        vector<int> P(n);
        for (int i = 0; i < n; i++) {
            P[pref[i].second] = n-1-i;
        }
        for (int i = 0; i < n; i++) {
            cout << P[i]+1 << " ";
        }
        cout << '\n';
    }
    return 0;   
}