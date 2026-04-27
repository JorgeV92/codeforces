#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) {
        int n; cin>>n;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin>>a[i];
            a[i]--;
        }
        int i=0;
        while (i < n && a[i]==a[n-i-1]) {
            i++;
        }
        if (i==n) {
            cout<<"YES\n";
            continue;
        }
        bool ok=false;
        for (int x : {a[i], a[n-i-1]}) {
            auto b = a;
            b.erase(std::remove(b.begin(), b.end(), x), b.end());
            auto c = b;
            reverse(c.begin(), c.end());
            if (b==c) {
                ok=true;
                break;
            }
        }
        cout<<(ok ? "YES\n" : "NO\n");
    }
    return 0;
}