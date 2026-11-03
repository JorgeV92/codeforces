#include <algorithm>
#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n;
        std::vector<long long> a(n);
        for (long long &x : a) std::cin >> x;
        std::sort(a.begin(), a.end());
        long long cost = 0;
        for (int i = 1; i < n; i++) cost += (a[i] - a[i - 1]) * std::min(i, n - i);
        std::cout << cost << ' ' << a.back() - a.front() << '\n';
    }
    return 0;
}
