#include <iostream>
#include <vector>
using namespace std;

const int N = 300000;
int pref[N];

void solve() {
    int a, b;
    cin >> a >> b;
    int res = 0;
    b ^= pref[a];
    if (b == 0) {
        res = a;
    } else if (b != a) {
        res = a + 1;
    } else {
        res = a + 2;
    }   
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    pref[0] = 0;
    for (int i = 0;  i < N; i++) {
        pref[i+1] = pref[i] ^ i;
    }
    while (tt--) {
        solve();
    }
    return 0;   
}