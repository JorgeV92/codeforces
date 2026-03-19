#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];
        sort(b.begin(), b.end());
        cout << (unique(b.begin(), b.end()) == b.end() ? "NO" : "YES") << "\n";
    }
    return 0;
}