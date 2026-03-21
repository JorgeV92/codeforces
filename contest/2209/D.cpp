#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int cnt[3]{};
        cin >> cnt[0] >> cnt[1] >> cnt[2];
        char C[3]{'R', 'G', 'B'};
        string s= "";
        s.reserve(cnt[0]+cnt[1]+cnt[2]);

        while (true) {
            int mx = -1;
            int cand[3]{};
            int sz = 0;
            int len = s.length();
            for (int c = 0; c < 3; c++) {
                if (cnt[c] == 0) continue;
                if (len >= 1 && C[c] == s[len-1]) continue;
                if (len >= 3 && C[c] == s[len-3]) continue;

                if (cnt[c] > mx) {
                    mx = cnt[c];
                    cand[0] = c;
                    sz = 1;
                } else if (cnt[c] == mx) {
                    cand[sz++] = c;
                }
            }

            if (sz == 0) break;
            int p = cand[0];
            if (sz > 1 && len >= 2) {
                char t = s[len-2];
                for (int i = 0; i < sz; i++) {
                    if (C[cand[i]] == t) {
                        p = cand[i];
                        break;
                    }
                }
            }
            s += C[p];
            cnt[p]--;
        }

        cout << s << '\n';
        
    }
    return 0;
}   