#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int n, m; std::cin >> n >> m;
    std::vector<int> a(n); for (int& x : a) std::cin >> x;
    std::vector<int> pref(n+1); for (int i =0 ; i < n; ++i) pref[i+1] = pref[i] + a[i];
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int l, r; std::cin >> l >> r;
        l--; r--;
        int sum = pref[r+1]-pref[l];
        if (sum > 0) ans+=sum;
    }
    std::cout << ans << '\n';
    return 0;
}