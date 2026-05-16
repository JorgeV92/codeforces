#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <cstdint>
using namespace std;
map<int,int64_t> dp;
map<int,int64_t> res;
auto gcd(int a, int b) -> int { return a ? gcd(b%a, a) : b; }
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        map<int,int64_t> ndp;
        ndp[v]++;
        res[v]++;
        for (auto it : dp) {
            ndp[gcd(it.first, v)] += it.second;
            res[gcd(it.first, v)] += it.second;
        }
        dp = ndp;
    }
    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int x; cin >> x;
        cout << res[x] << '\n';
    }
    return 0;
}