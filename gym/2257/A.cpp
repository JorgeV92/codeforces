#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        set<char> st;
        for (int i = 0; i < n; ++i) {
            string s; cin >> s;
            st.insert(::toupper(s[0]));
        } 
        bool valid = true;
        for (int i = 0; i < m; i++) {
            string s; cin >> s;
            for (char c : s) {
                if (!st.contains(c)) {
                    valid = false;
                    break;
                }
            }
        }
        if (valid) cout << "YES\n";
        else cout << "NO\n";
        
    }
    return 0;
}