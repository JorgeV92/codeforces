#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        if (n == 1 || n == 4 || n == 7) {
            cout << 1 << '\n';
        } else if (n == 2) {
            cout << 2 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
    return 0;
}