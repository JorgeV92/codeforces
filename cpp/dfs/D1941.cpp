#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    auto jorgee = [&]() -> void {
        int T; cin >> T;
        while (T--) {
            int n, m, x; cin >> n >> m >> x;
            vector<int> f(n);
            x--;
            f[x] = 1;
            for (int i = 0; i < m; i++) {
                int r; char c;
                cin >> r >> c;
                vector<int> nf(n);
                for (int j =0; j < n; j++) {
                    if (f[j]) {
                        if (c != '1') {
                            nf[(j+r) % n] = 1;
                        } 
                        if (c != '0') {
                            nf[(j-r+n)%n] = 1;
                        }
                    }
                }
                f = nf;
            }
            int ans = count(f.begin(), f.end(), 1);
            cout << ans << '\n';
            for (int i =0; i < n; i++) {
                if (f[i]) {
                    cout << i + 1 << ' ';
                }
            }
            cout << '\n';
        }
    }; jorgee();
    return 0;
}