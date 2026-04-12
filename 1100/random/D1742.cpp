#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) {
        int n; cin>>n;
        vector<int> pos(1001);
        for (int i=0;i<n;i++) {
            int x; cin>>x;
            pos[x]=i+1;
        }
        int ans=-1;
        for (int i=1;i<=1000;i++) {
            for (int j=1;j<=1000;j++) {
                if (pos[i] && pos[j] && gcd(i,j)==1) {
                    ans=max(ans,pos[i]+pos[j]);
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}