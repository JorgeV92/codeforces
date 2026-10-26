#include <algorithm>
#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    auto possible = [&](const std::vector<int> &a, int x, int k) {
        int n = a.size();
        std::vector<int> isolated;
        for (int i = 0; i < n; i++) {
            int nearest = 1e9;
            if (i > 0) nearest = std::min(nearest, a[i] - a[i - 1]);
            if (i + 1 < n) nearest = std::min(nearest, a[i + 1] - a[i]);
            if (nearest > k) isolated.push_back(a[i]);
        }
        int needed = isolated.size();
        for (int i = 0; i + 1 < (int) isolated.size(); i++) {
            if (isolated[i + 1] - isolated[i] <= 2LL * k) {
                needed--;
                i++;
            }
        }
        return needed <= x;
    };
    int T; std::cin >> T;
    while (T--) {
        int n, x; std::cin >> n >> x;
        std::vector<int> a(n);
        for (int &v : a) std::cin >> v;
        int low = 1, high = 1e9;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (possible(a, x, mid)) high = mid;
            else low = mid + 1;
        }
        std::cout << low << '\n';
    }
    return 0;
}
