#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

void solve(){

    auto ask = [&](int u, int v, int d) -> int {
        cout << "? " << u << ' ' << v << ' ' << d << endl;
        int res; cin >> res;
        if (res==-1) exit(0);
        return res;
    };
    int n; cin>>n;
    int far=0, u=1;
    for (int v=1; v<=n; ++v) {
        while (far<n && ask(1,v,far+1)) {far++; u=v; }
    }
    int diameter=far;
    int v=1;
    for (int x=1; x<=n; x++) {
        while (diameter<n && ask(u,x,diameter+1)) { diameter++; v=x; }
    }
    cout << "! " << u << ' ' << v << ' ' << diameter << endl; 
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}