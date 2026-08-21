#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        int m = 2*n;
        int p = 0, red = 0;
        for (int i = 0; i < m; ++i) {
            if (s[i] == '1') {
                p++;
                if (i%2==1) red++;
            }
        }
        for (int i = 0; i < m; ++i) {
            int j = (i+1)%m;
            if (s[i] == '1' && s[j] == '0') {
                if (i%2==0) red++;
                else red--;
            }
        }
        int blue = p - red;
        cout << red << ' ' << blue << '\n';
    }
    return 0;
}   