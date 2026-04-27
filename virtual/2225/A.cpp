#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t x, y; cin>>x>>y;
        int64_t ans = -1;
        if (y == 2*x) {
            cout<<"NO\n";
        } else {
            cout<<"YES\n";
        }
        
    }
    return 0;
}