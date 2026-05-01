#include <iostream>
#include <vector>
#include <string>
#include <string_view>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        int cntL = 0, cntR = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                cntL++;
            } else {
                cntR++;
            }
        }
        cout << (cntL == cntR ? "YES" : "NO") << '\n';
        
    }
    return 0;
}
