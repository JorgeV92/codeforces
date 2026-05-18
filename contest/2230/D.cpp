#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n+1), b(n+1); 
        vector<vector<int>> pa(n+2), pb(n+2);
        for (int i = 1; i <= n; ++i) {
            cin >>a[i];
            pa[a[i]].push_back(i);
        }
        for (int i = 1; i <= n; ++i) {
            cin>>b[i];
            pb[b[i]].push_back(i);
        }
        auto aa = [&](int idx, int x) {
            if (x > n) return n+1;
            auto it = upper_bound(pa[x].begin(), pa[x].end(), idx);
            return (it == pa[x].end()) ? (n+1) : *it;
        };
        auto bb = [&](int idx, int x) {
            if (x > n) return n+1;
            auto it = upper_bound(pb[x].begin(), pb[x].end(), idx);
            return (it == pb[x].end()) ? (n+1) : *it;
        };
        vector<int> nxtL(n+2);
        for (int i = n; i>=1; --i) {
            if (a[i] == b[i]) {
                int k = a[i];
                int pA = aa(i,k+1);
                int pB = bb(i,k+1);

                if (pA == pB) {
                    if (pA == n+1) 
                        nxtL[i] = n+1;
                    else 
                        nxtL[i] = nxtL[pA];
                } else {
                    nxtL[i] = min(pA,pB);
                }
            } 
        }
        int64_t ans = 0;
        for (int L = 1; L <= n; ++L) {
            int pA = aa(L-1,1);
            int pB = bb(L-1, 1);
            int li;
            if (pA == pB) {
                if (pA == n+1) 
                    li = n+1;
                else   
                    li = nxtL[pA];
            } else {
                li = min(pA,pB);
            }
            if (li > L)
                ans += (li - L);
        }
        cout << ans<<'\n';

    }
    return 0;
}