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
        char d1, d2; cin >> d1 >> d2;
        int64_t a = stoll(s); int sz = s.size();
        vector<int64_t> v;
        if (sz > 1) {
            string c1(sz-1, d2);
            v.push_back(stoll(c1));
        }
        if (d1 != '0') {
            string c2(sz+1,d1);
            v.push_back(stoll(c2));
        } else {
            string c2 = string(1,d2) + string(sz,'0');
            v.push_back(stoll(c2));
        }

        auto pre_good = [&](const string& t) {
            bool good = true;
            for (char c : t) {
                if (c != d1 && c != d2) {
                    good = false;
                    break;
                }
            }
            return good;
        };

        for (int i=0; i <= sz; ++i) {
            if (i < sz) {
                string p = s.substr(0, i);
                if (!pre_good(p)) break;
                char x = 0;
                if (d2 < s[i]) 
                    x = d2;
                else if (d1 < s[i])
                    x = d1;
                if (x != 0) {
                    string ca = p + x + string(sz-1-i,d2);
                    v.push_back(stoll(ca));
                }
                char y = 0;
                if (d1 > s[i]) 
                    y = d1;
                else if (d2 > s[i])
                    y= d2;
                if (y !=0) {
                    string ca = p + y + string(sz-1-i,d1);
                    v.push_back(stoll(ca));
                }
            } else {
                if (!pre_good(s)) break;
                v.push_back(stoll(s));
            }
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