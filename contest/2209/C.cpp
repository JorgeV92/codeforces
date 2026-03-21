#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

#define OUT(k) cout << "! " << (k) << '\n'; cout.flush();

int ask(int i, int j) {
    cout << "? " << i << " " << j << "\n";
    cout.flush();
    int res;
    cin >> res;
    if (res == -1) exit(0);
    return res;
}

void solve() {
    int n;
    cin >> n;
    if (ask(1, 2) == 1) {
        OUT(1);
        return;
    }
    if (ask(2, 3) == 1) {
        OUT(2);
        return;
    }
    if (ask(1, 3) == 1) {
        OUT(1);
        return;
    }
    bool valid = false;
    for (int i = 5; i <= 2*n; i += 2) {
        if (ask(i, i + 1) == 1) {
            OUT(i);
            valid = true;
            break;
        }
    } 
    if (!valid) {
        OUT(4);
    }
}

int main( ){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}