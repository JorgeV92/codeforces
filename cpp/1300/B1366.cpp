#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin>>T;
    while (T--) {
        int n,x,m; cin>>n>>x>>m;
        int L=x, R=x;
        for (int i=0; i<m; i++) {
            int l,r; cin >>l>>r;
            if (l<=R && L<=r) {
                L=min(l,L);
                R=max(r,R);
            }
        }
        cout<<(R-L+1)<< "\n";
    }
    return 0;
}