#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdint>
using namespace std;
const int mod = 998244353;
const int maxn = 2e5 + 5;
int64_t fac[maxn+1];
void factorial() {
    fac[0] = 1;
    for (int i=1; i<=maxn; ++i) {
        fac[i] = fac[i-1] * i % mod;
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    factorial();
    while (T--) {
        string s; cin >> s;
        int n = s.size();
        int64_t d = 0;
        int64_t ways = 1;
        for (int i=0; i<n; ++i) {
            int j = i+1;
            while (j < n && s[j] == s[i]) {
                j++;
            }
            // cout << j-i<<'\n';
            d += (j-i-1);
            ways = ways*(j-i) % mod;
            i = j-1;
        }
        ways = ways * fac[d] % mod;
        cout<<d<<' '<<ways << '\n';
    }
    return 0;
}