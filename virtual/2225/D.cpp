#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;
const int mod = 998244353;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) {
        int64_t n, x; cin>>n>>x;
        auto zero_cnt = [&](int64_t m) -> int64_t {
            if (m<0) return 0;
            return 1+(m+1)/4;
        };
        auto one_cnt = [&](int64_t m) -> int64_t {
            if (m<0) return 0;
            return (m+3)/4;
        };
        int64_t zl = zero_cnt(x-1);
        int64_t ol = one_cnt(x-1);
        int64_t zr = zero_cnt(n) - zl;
        int64_t orr = one_cnt(n) - ol;
        int64_t ans=0;
        ans = (ans + (__int128_t)(zl % mod) * (zr % mod)) % mod;
        ans = (ans + (__int128_t)(ol % mod) * (orr % mod)) % mod;
        cout <<ans%mod<<'\n';
    }
    return 0;
}