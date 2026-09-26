#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> pos(n + 1);
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            pos[x] = i;                 
        }

        int q = pos[n] & 1;            
        int c = q ^ 1;         
        int u = 0;
        bool ok = true;

        for (int v = n - 1; v >= 1; v -= 2) {
            if ((pos[v] & 1) != c) { ok = false; break; }  
            if (v - 1 >= 1 && (pos[v - 1] & 1) == c) {      
                u++;                                         
                c ^= 1;                                    
            }
        }

        if (!ok) cout << "NO\n";
        else if (n % 2 == 1 && (u & 1) != (q ^ 1)) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}