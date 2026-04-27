#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;
int main() {    
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) {
        int64_t n, k; cin>>n>>k;
        vector<int64_t> a(n);
        for (int i=0; i<n; i++) {
            cin>>a[i];
        }
        bool ok=false;
        sort(a.begin(), a.end());
        for (int i=0, j=0; i< n; i++) {
            while (j<n && a[j] < a[i] + k) j++;
            if (j<n && a[j]==a[i]+k) {
                ok=true;
                break;
            }
        }
        cout<<(ok ? "YES\n" : "NO\n");
    }
    return 0;   
}