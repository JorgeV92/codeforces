#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        int ans = 0;
        for (int i = 0; i < n; i += k) {
            bool ones = true;
            for (int j= i; j < i + k; j++) {
                if (s[j] == '0') {
                    ones = false; 
                    break;
                }
            }
            if (ones) ans++;
        }
        cout << ans << '\n';
        
    }
    return 0;
}