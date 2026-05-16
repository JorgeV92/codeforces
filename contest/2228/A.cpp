#include <iostream>
#include <vector>
#include <numeric>
#include <cstdlib>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> cnt(3); 
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            cnt[x]++;
        }
        int ans = 0;
        ans += cnt[0];
        int p = min(cnt[1], cnt[2]);
        ans += p;
        cnt[1]-= p;
        cnt[2] -= p;
        ans += cnt[1] / 3;
        ans += cnt[2] / 3;
        cout<<ans<<'\n';
    }
    return 0;
}