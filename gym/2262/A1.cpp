#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std; 
void solve() {
    int n; cin >> n;
    vector<int> A(n); for (int& i : A) cin>>i;
    set<int> S;
    for (int i = 0; i < n; ++i) S.insert(i);
    for (int i = 1; i <= n; ++i) {
        int m = A.at(i-1);
        while (true) {
            auto it = S.lower_bound(m*i);
            if (it != S.end() && *it < (m+1)*i) {
                S.erase(it);
            } else {
                break;
            }
        }
    }
    cout << S.size() << '\n';
    for (int x : S) cout << x << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}