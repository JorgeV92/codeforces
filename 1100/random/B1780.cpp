#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) {
        int n; cin>>n;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin>>a[i];
        }
        int64_t sum = accumulate(a.begin(), a.end(), 0LL);
        int64_t pref=0, ans=1;
        for (int i=0; i<n-1; i++) {
            pref+=a[i];
            ans=max(ans,gcd(sum,pref));
        }
        cout<<ans<<'\n';
        
    }
    return 0;
}