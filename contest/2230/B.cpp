#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        string s; cin>>s;
        int n = s.size();
        vector<int> pref(n+1), suf(n+1);
        for (int i = 0; i < n; ++i) {
            pref[i+1]=pref[i] + (s[i] =='2');
        }
        for (int i = n-1; i >= 0; --i) {
            suf[i] = suf[i+1] + (s[i]=='1' || s[i]=='3');
        }
        int mx = 0;
        for (int i = 0; i <= n; ++i) {
            mx = max(mx, pref[i]+suf[i]);
        }
        cout << n-mx<<'\n';
    }
    return 0;
}