#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; string s; cin >>n >> s;
        int cnt = 0;
        for (int i = 0; i < n-2; i++) {
            if (s[i] == s[i+2]) cnt++;
        }
        cout << (n-cnt-1) << '\n';
    }
    return 0;   
}