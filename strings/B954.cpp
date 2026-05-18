#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    string s; cin>>s;
    int d = 0;
    for (int i = 1; i*2 <= n; ++i) {
        string t1 = s.substr(0, i);
        string t2 = s.substr(i, i);
        if (t1 == t2) d = i;
    }
    int ans = n;
    if (d > 0) ans = n - d + 1;
    cout<<ans<<'\n';
    return 0;
}