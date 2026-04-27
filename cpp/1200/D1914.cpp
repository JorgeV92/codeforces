#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n), b(n), c(n);
        for (int i=0; i<n; i++) cin>>a[i];
        for (int i=0; i<n; i++) cin>>b[i];
        for (int i=0; i<n; i++) cin>>c[i];
        vector<int> pa(n), pb(n), pc(n);
        iota(pa.begin(), pa.end(), 0);
        iota(pb.begin(), pb.end(), 0);
        iota(pc.begin(), pc.end(), 0);
        sort(pa.begin(), pa.end(), [&](int i, int j) {return a[i]>a[j];});
        sort(pb.begin(), pb.end(), [&](int i, int j){return b[i]>b[j];});
        sort(pc.begin(), pc.end(), [&](int i, int j){return c[i]>c[j];});
        int ans = 0;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                for (int k=0; k<3; k++) {
                    int x = pa[i], y = pb[j], z = pc[k];
                    if (x != y && y != z && x != z) {
                        ans = max(ans, a[x]+b[y]+c[z]);
                    }
                }
            }
        }
        cout<<ans<<'\n';

    }
    return 0;
}