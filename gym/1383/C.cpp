#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <numeric>
#include <functional>
using namespace std;
int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int n; string a, b;
        cin >> n >> a >> b;
        int req[20] = {}, activeMask = 0;
        for (int i = 0; i < n; i++) if (a[i] != b[i]) {
            req[a[i]-'a'] |= 1 << (b[i]-'a');
            activeMask |= (1 << (a[i]-'a')) | (1 << (b[i]-'a'));
        }
        int par[20]; iota(par, par+20, 0);
        function<int(int)> find = [&](int x){ return par[x]==x ? x : par[x]=find(par[x]); };
        for (int x = 0; x < 20; x++)
            for (int y = 0; y < 20; y++)
                if (req[x]>>y & 1) par[find(x)] = find(y);
        int wsz[20] = {}, base = 0, A = 0;
        for (int x = 0; x < 20; x++) if (activeMask>>x & 1) { wsz[find(x)]++; A++; }
        for (int x = 0; x < 20; x++) if (wsz[x]) base += wsz[x] - 1;
        int L[20], k = 0, inmask[20] = {};
        for (int x = 0; x < 20; x++) if (activeMask>>x & 1) L[k++] = x;
        for (int i = 0; i < k; i++)
            for (int j = 0; j < k; j++)
                if (req[L[j]] >> L[i] & 1) inmask[i] |= 1 << j;
        static char f[1 << 20];
        memset(f, 0, 1 << k);
        f[0] = 1; int best = 0;
        for (int S = 1; S < (1 << k); S++) {
            for (int m = S; m; m &= m-1) {
                int low = m & -m, i = __builtin_ctz(low);
                if ((inmask[i] & (S ^ low)) == 0 && f[S ^ low]) { f[S] = 1; break; }
            }
            if (f[S]) best = max(best, __builtin_popcount(S));
        }
        printf("%d\n", base + (A - best));
    }
}