#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int k; cin >> k;
        vector<int> c(k); for (int i = 0; i < k; i++) cin >> c[i];
         bool good = false;
         int cnt = 0;
         for (int i = 0; i < k; i++) {
            if (c[i] >= 3) {
                good = true;
                break; 
            } else if (c[i] >= 2) {
                cnt++;
            }
         }
         if (cnt >= 2) {
            cout << "YES\n";
         } else {
            cout << (good ? "YES" : "NO") << '\n';
         }
    }
    return 0;
}