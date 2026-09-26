#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <bitset>
using namespace std;
typedef long long ll;

const int V = 300000;

int main() {
    int t;
    scanf("%d", &t);
    static int cnt[V + 1];
    static int idx[V + 1];          
    while (t--) {
        int n, x;
        scanf("%d %d", &n, &x);
        vector<int> vals;           
        for (int i = 0; i < n; i++) {
            int v; scanf("%d", &v);
            if (cnt[v]++ == 0) vals.push_back(v);
        }
        vector<int> divs;
        for (int d = 1; (ll)d * d <= x; d++)
            if (x % d == 0) {
                if (d >= 2) divs.push_back(d);
                if (d != x / d && x / d >= 2) divs.push_back(x / d);
            }
        sort(divs.rbegin(), divs.rend());
        int D = divs.size();
        for (int i = 0; i < D; i++) idx[divs[i]] = i;

        vector<ll> S(D, 0);
        vector< bitset<256> > H(D);
        for (int v : vals) {
            for (int i = 0; i < D; i++) {
                int d = divs[i];
                if (v % d == 0) S[i] += (ll)v * cnt[v];
                int g = gcd(v, d);
                if (g >= 2) H[i].set(idx[g]);
            }
        }

        bitset<256> reach;
        ll ans = 0;
        for (int i = 0; i < D; i++) {         
            if (divs[i] == x || reach.test(i)) {
                reach |= H[i];
            }
        }
        for (int i = 0; i < D; i++)
            if (reach.test(i)) ans = max(ans, S[i]);
        printf("%lld\n", ans);
        for (int v : vals) cnt[v] = 0;
        for (int d : divs) idx[d] = -1;
    }
    return 0;
}