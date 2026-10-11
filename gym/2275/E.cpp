#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n;
        std::vector<ll> a(n+1), b(n+1);
        for (int i = 1; i <= n; i++) std::cin >> a[i];
        for (int i= 1; i <= n; i++) std::cin >> b[i];
        std::vector<int> wV(n+1), wU(n+1), wL(n+1);
        ll sumL = 0, sumU = 0;
        for (int i = 1; i <=n; i++) wV[i] = (a[i] == b[i]) ? 2 : 1;
        for (int i = 1; i < n; ++i) { wU[i] = (a[i] == b[i+1]) ? 2 : 1; sumU += wU[i]; }
        for (int i = 2; i <= n; i++) {wL[i] = (a[i] == b[i-1]) ? 2 : 1; sumL += wL[i]; }
        ll ans = 0, prefV = 0, suffU = sumU;
        for (int m = 1; m <= n; m++) {
            ans = std::max(ans, sumL + prefV + suffU + wV[n]);
            prefV += wV[m];
            if (m < n) suffU -= wU[m];
        } 
        std::cout << ans << '\n';
    }
    return 0;
}   