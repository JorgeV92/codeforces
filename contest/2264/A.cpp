#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve() {
    int n; cin >> n;
    vector<int> p(n); for (int& i : p) cin >> i;
    vector<int> b; 
    for (int i = 0; i < n; ++i) { if (p[i] != i+1) b.push_back(i+1); }
    int k = b.size();
    for (int i = 0; i < k; i++) {
        int pos = b[i];
        int e = b[k-1-i];
        if (p[pos-1] != e) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;   
}