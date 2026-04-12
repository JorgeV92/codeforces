#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;
const int maxn = 1e5+7;
int a[maxn];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) {
        int n,l,r; cin>>n>>l>>r;
        bool ok = true;
        for (int i=1; i<=n; i++) {
            a[i] = ((l-1)/ i + 1) * i;
            ok = ok && a[i] <= r;
        }
        if (ok) {
            cout<<"YES\n";
            for (int i=1; i<=n; i++) {
                cout<<a[i]<<' ';
            }
            cout<<'\n';
        } else {
            cout<<"NO\n";
        }
    }
    return 0;
}