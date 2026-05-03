#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    auto jorgee = [&]() -> void {
        int T; cin >> T;
        while (T--) {
            int n; cin >> n;
            vector<int> p(n); for (int i = 0; i < n; i++) cin >> p[i];
            vector<int> ans(n);
            function<void(int,int,int)> dfs = [&](int l, int r, int d) {
                if (l >= r) return;
                int i = max_element(p.begin() + l, p.begin() + r) - p.begin();
                ans[i] = d;
                dfs(l, i, d+1);
                dfs(i+1,r, d+1);
            }; dfs(0, n,0);

            for (int i = 0; i < n; i++) {
                cout << ans[i] << ' ';
            }
            cout << '\n';
        }
    }; jorgee();
    return 0;
}