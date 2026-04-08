#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; std::cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> c(n);
        for (int i=0; i<n; i++) {
            cin>>c[i];
        }
        sort(c.begin(),c.end());
        if (c[0] != 1) {
            cout << "NO\n";
            continue;
        }
        bool flag = true;
        int64_t sum = c[0];
        for (int i=1; i<n; i++) {
            if (sum<c[i]) {
                flag = false;
                break;
            }
            sum+=c[i];
        }
        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } 
    return 0;
}
