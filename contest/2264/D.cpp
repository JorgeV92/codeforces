#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std; 
void solve() {
    int n; cin >> n;
    if (n==1) {
        cout << "1\n";
        return;
    }
    if (n==2) {cout << "11\n"; return; }
    int N = n+1;
    int q = N/3;
    int r = N%3;
    vector<int> pp(3, q);
    for (int i = 0; i < r; i++) pp[i]++;
    string s(n,'0');
    int mid = -1;
    for (int i = 0; i < 3; ++i) {
        if (pp[i]%2==0) { mid = i; break; } 
    }
    if (mid != -1) {
        int B = pp[mid];
        vector<int> o;
        for (int i = 0; i < 3; i++) {
            if (i != mid) o.push_back(pp[i]);
        }
        int A = o[0];
        s[A-1] = '1';
        s[A+B-1] = '1';
    } else {
        int p1 = q-2, p2 = 2*q-2, p3 = 2*q;
        s[p1-1] = '1';
        s[p2-1] = '1';
        s[p3-1] = '1';
    }
    cout << s << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}