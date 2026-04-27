#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i<n; i++) {
            cin >> a[i];
        }
        reverse(a.begin(), a.end());
        int cnt=0;
        for (int i =0; i<n;) {
            if (a[i]==a[0]) {
                i++;
            } else {
                i *= 2;
                cnt++;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}