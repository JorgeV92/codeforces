#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        // cab -> ab -> a 
        // cababa
        string s; cin >> s;
        ll pos; cin >> pos;
        ll len = s.size();
        int del = 0;
        while (pos > len) {
            pos -= len;
            --len;
            ++del;
        }
        string st;
        int k = del;
        for (char cc : s) {
            while (k > 0 && st.back() > cc) {
                st.pop_back();
                k--;
            }
            st.push_back(cc);
        }
        while (k > 0) {
            st.pop_back(); k--;
        }
        cout << st[pos-1];
    }
    cout << '\n';
    return 0;
}