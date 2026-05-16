#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdint>
using namespace std;
int main() {    
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        string s; int n; cin >> s >> n;
        vector<char> dg(n); for (int i = 0; i < n; i++) cin>>dg[i];
        int64_t a = stoll(s); int sz = s.size();
        vector<int64_t> v;
        if (sz > 1) {
            if (dg.back() != '0') {
                string c1(sz-1, dg.back());
                v.push_back(stoll(c1));
            } else {
                v.push_back(0);
            }
        }

        char d1 = 0;
        for (char c : dg) {
            if (c > '0') {
                d1 = c;
                break;
            }
        }
        if (d1 != 0) {
            string c2 = string(1, d1) + string(sz, dg.front());
            v.push_back(stoll(c2));
        } else {
            v.push_back(0);
        }
        for (int i=0; i < sz; ++i) {
            string p = s.substr(0,i);
            char x = 0;
            for (char c : dg) {
                if (c < s[i]) {
                    x = c;
                }
            }
            if (x!=0) {
                string ca = p + x + string(sz-i-1, dg.back());
                v.push_back(stoll(ca));
            }
            char y = 0;
            for (int j = n-1; j >= 0; --j) {
                if (dg[j] > s[i]) {
                    y = dg[j];
                }
            }
            if (y != 0) {
                string ca = p + y + string(sz-i-1,dg.front());
                v.push_back(stoll(ca));
            }
            bool match = false;
            for (char c : dg) {
                if (c == s[i]) {
                    match = true;
                    break;
                }
            }
            if (!match) break;
            if (i == sz-1 && match) {
                v.push_back(a);
            }
        }
        if (n==1 && dg[0]=='0') {
            v.push_back(0);
        }
        int64_t d = 2e18;
        for (int64_t b : v) {
            int64_t dd = (a > b) ? (a-b) : (b-a);
            if (dd < d) {
                d = dd;
            }
        }
        cout<<d<<'\n';
    }
    return 0;   
}