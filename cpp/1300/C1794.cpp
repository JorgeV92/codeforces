#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin>>T;
    while (T--) {
        int n; cin>>n;
        vector<int> a(n); 
        for (int i = 0, k=0; i < n; ++i) {
            cin>>a[i];
            while (k <= i && a[i-k] >= k+1) {
                k += 1;
            }
            cout<<k<<' ';
        }
        cout<<'\n';
    }
    return 0;
}