#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; char c; string s; cin >> n >> c >> s;
        int cnt = count(s.begin(), s.end(), c);
        if (n == cnt) {
            cout << 0 << '\n'; 
            continue;
        }
        int op = -1;
        for (int x = 1; x <= n; ++x) {
            bool good = true;
            for (int j = x; j <= n; j += x) {
                if (s[j-1] != c) {
                    good = false;
                    break;
                }
            }
            if (good) {
                op = x;
                break;
            }
        }
        if (op != -1) {
            cout << 1 << '\n';
            cout << op << "\n";
        } else {
            cout << 2 << '\n';
            cout << n-1 << ' ' << n << '\n';
        }
    }
    return 0;
}