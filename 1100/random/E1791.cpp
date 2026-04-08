#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdint>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) {
        int n; cin>>n;
        vector<int> a(n);
        for (int i=0; i<n; i++) 
            cin>>a[i];
        int64_t sum = 0;
        int64_t neg = 0;
        int mn = 1e9;
        for (int i=0; i<n; i++) {
            if (a[i]<0)
                neg++;
            sum+=abs(a[i]);
            mn=min(mn,abs(a[i]));
        }
        if (neg % 2 ==0) {
            cout << sum << "\n";
        } else {
            cout << sum-2*mn << '\n';
        }
    }
    return 0;
}