#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin>>T;
    while (T--) {
        int n; cin>>n;
        int zz = 0, oo = 0;
        int odd = 0;
        for (int i = 0 ; i < n; ++i) {
            string s; cin >> s;
            if ((int)s.size() % 2 == 1) odd++;
            zz += count(s.begin(), s.end(), '0');
            oo += count(s.begin(), s.end(), '1');
        }   
        if ((zz%2==1) && (oo%2==1) && odd == 0) {
            cout<<n-1<<'\n';
        } else {
            cout<<n<<'\n';
        }
    }
    return 0;
}