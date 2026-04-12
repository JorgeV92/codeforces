#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) {
        string s; cin>>s;
        int n=s.size();
        set<char> st;
        int k;
        for (k=0; k<n; k++) {
            if (st.find(s[k]) == st.end()) {
                st.insert(s[k]);
            } else {
                break;
            }
        }
        bool ok = true;
        for (int i=k; i<n; i++) {
            if (s[i]!=s[i-k]) {
                ok=false;
                break;
            }
        }
        if (ok) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }
    return 0;
}