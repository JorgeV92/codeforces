#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin>>n;
        vector<int> p(n);
        int ans=-1;
        for (int i=0; i < n; i++) {
            cin>>p[i];
            if (p[i] != i) {
                ans &= i;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;   
}