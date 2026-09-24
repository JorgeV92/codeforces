#include <iostream>
#include <vector>
#include <unordered_map>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int n, k; std::cin >> n >> k;
    std::vector<int64_t> a(n); for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::unordered_map<int64_t, int> freq;
    int64_t ans = 0;
    int l = 0;
    for (int r = 0; r < n; ++r) {
        freq[a[r]]++;
        while ((int)freq.size() > k)  {
            if (--freq[a[l]] == 0) freq.erase(a[l]);
            l++;
        }
        ans += r - l + 1;
    }
    std::cout << ans << '\n';
    return 0;
}