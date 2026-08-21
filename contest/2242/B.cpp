#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n), s1(n+1), s2(n+1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i-1];
            int v1 = (a[i-1] == 1) ? 1 : -1;
            int v2 = (a[i-1] != 3) ? 1 : -1;
            s1[i] = s1[i-1] + v1;
            s2[i] = s2[i-1] + v2; 
        }
        int min_s2 = 1e9;
        bool found = false;
        for (int j = 2; j < n; ++j) {
            int i = j - 1;
            if (s1[i] >= 0) {
                min_s2 = min(min_s2, s2[i]);
            }
            if (s2[j] >= min_s2) {
                found = true;
                break;
            }
        } 
        if (found) cout << "YES\n";
        else cout << "NO\n";
    }       
    return 0;
}