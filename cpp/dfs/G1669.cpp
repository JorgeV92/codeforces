#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    auto jorgee = [&]() -> void {
        int T; cin >> T;
        while (T--) {
            int n, m; cin >> n >> m;
            vector<string> g(n); for (int i = 0; i < n; i++) cin >> g[i];
            for (int j = 0; j < m; j++) {
                int last = n;
                for (int i = n-1; i >= 0; i--) {
                    if (g[i][j] == 'o') {
                        last = i;
                    } else if (g[i][j] == '*') {
                        g[i][j] = '.';
                        last--;
                        g[last][j] = '*';
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                cout << g[i] << '\n';
            }
        }
    }; jorgee();
    return 0;
}