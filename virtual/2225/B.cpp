#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) {
        string s; cin>>s;
        int cnt = 0;
        for (int i=0; i<(int)s.size()-1; i++) {
            if (s[i] == s[i+1]) cnt++;
        }
        cout<<(cnt<=2 ? "YES\n" : "NO\n");
    }
    return 0;
}
