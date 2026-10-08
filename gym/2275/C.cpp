#include <iostream>
#include <vector>
typedef long long ll;
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n;
        std::vector<int> a(n+1);
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        int m = n-4;
        const int OFF = 30000;
        std::vector<int> freq(60001, 0);
        std::vector<int> v(m+1);
        ll ans = 0;
        for (int x = 1; x <= m; x++) {
            v[x] = a[x] + a[x+2] - a[x+4];
            ans += freq[v[x] + OFF];
            if (x-2 >= 1 && v[x-2] == v[x]) ans--;
            if (x-4 >= 1 && v[x-4] == v[x]) ans--;
            freq[v[x]+OFF]++;
        }
        std::cout << ans << '\n';
    }
    return 0;
}