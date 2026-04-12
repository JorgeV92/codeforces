#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;
int main() {    
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) {
        int n; cin>>n;
        vector<int> w(n);
        for (int i = 0 ; i < n; i++) {
            cin>>w[i];
        }
        int64_t A =0, B=0;
        int ans =0;
        for (int i=0, j=n-1; i< n; i++ ){
            A += w[i];
            while (A > B) {
                B += w[j];
                j--;
            }
            if (A==B && i<=j) {
                ans = max(ans, i+n-j);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;   
}