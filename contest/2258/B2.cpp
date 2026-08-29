#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
void solve() {
    int n, m; cin >>n>>m;
    vector<ll> f(m+1); for (int i = 0; i < n; ++i) { int x;cin>>x;f[x]++;}
    vector<ll> suf(m+2); for (int x =m; x>=1; x--) { suf[x] = suf[x+1]+f[x]; }
    int K=1; while ((1LL<<K)< m) K++;
    vector<ll> ans(K+1);
    for (int d=1; d<=m; d++) {
        ll sum=0;
        ll L=2;
        int k=1;
        for (int q=1; q*d <= m; ++q) {
            sum+=suf[q*d];
            if (k<=K && q==L-1) {
                ll cur=sum;
                if (L*d<=m) cur+=f[L*d];
                ans[k]=max(ans[k],cur);
                ++k; L*=2;
            }
        }
        while (k<=K) {
            ans[k]=max(ans[k],sum);
            ++k; L*=2;
        }
    }
    for (int k=1;k<=m;k++) {
        int use=min(k,K);
        cout<<ans[use]<<' ';
    }
    cout<<'\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}