#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> f(m+1); for (int i = 0; i < n; ++i) {int x; cin >>x; f[x]++; }
    vector<int> suf(m+2,0); for (int x = m; x >= 1; x--) { suf[x]= suf[x+1] + f[x]; }
    int ans = 0;
    for (int x=1; x<=m; x++) { 
        int cur = suf[x];
        if (2*x <= m) cur+=f[2*x];
        ans=max(ans,cur);
    }
    cout<<ans<<'\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}