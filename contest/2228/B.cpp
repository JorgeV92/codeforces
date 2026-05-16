#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cstdlib>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int64_t n, x1, x2, k; cin >> n >> x1 >> x2 >> k;
        if (n <= 3) {
            cout << 1 << '\n';
            continue;
        }
        int64_t dist = min(abs(x1-x2), n-abs(x1-x2));
        cout << dist + k << '\n';
    }
    return 0;
}