#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    auto run = [&]() -> void {
        int n; cin >> n;
        vector<vector<pair<int,int>>> ring(n);
        for (int i = 0; i < n; i++) {
            int x, y, c; cin >> x >> y >> c;
            x--; y--;
            ring[x].push_back({y, 0});
            ring[y].push_back({x, c});
        }
        int ans = 1e9;
        for (auto [y, c] : ring[0]) {
            int x = 0;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                for (auto [b, w] : ring[x]) {
                    if (y != b) {
                        y = b;
                        sum += w;
                        break;
                    }
                }
                swap(x, y);
            }
            ans = min(ans, sum);
        }
        cout << ans << '\n';
    }; run();
    return 0;
}