#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 2; i <= n; ++i) {
            int p; cin >> p;
        }
        int m; cin >> m;
        vector<int> a(m);
        for (int &x : a) cin >> x;
        int y = *min_element(a.begin(), a.end());
        cout << m-1 << ' ';
        for (int x : a) {
            if (x != y) 
                cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;   
}