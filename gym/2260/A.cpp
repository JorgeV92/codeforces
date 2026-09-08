#include <iostream>
#include <vector>
using namespace std; 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t;
    while (t--){
        int n; cin >> n;
        int cnt=0;
        vector<int> a(n); for (int i =0; i<n; ++i) {cin>>a[i]; if (a[i]==0) cnt++; }
        if (a[0] == 1 && a[n-1] == 1) {
            if (cnt >= 2) cout<<2<<'\n';
            else cout<<-1<<'\n';
        } else if (a[0] == 1 || a[n-1] == 1) {
            if (cnt>=2) cout<<1<<'\n';
            else cout<<-1<<'\n';
        } else cout<<0<<'\n';
    }
    return 0;
}