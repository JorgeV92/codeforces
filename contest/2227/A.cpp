#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int x, y; cin >> x >> y;
        cout << ((x % 2 == 1 && y % 2 == 1) ? "NO" : "YES") << "\n";
    }
    return 0;
}