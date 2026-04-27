#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) {
        int n; cin>>n;
        vector<int64_t> a(n);
        for (int i =0; i<n; i++) {
            cin >>a[i];
        }
        for (int c : {0,1}) {
            int64_t g = 0;
            for (int i=c; i < n; i+=2) {
                g = std::gcd(g, a[i]);
            }
            bool ok=true;
            for (int i=!c; i < n; i+=2) {
                if (a[i]%g==0) {
                    ok=false;
                    break;
                }
            }
            if (ok) {
                cout<<g<<'\n';
                goto end;
            }
        }
        cout<<0<<'\n';
    end:;
    }
    return 0;
}