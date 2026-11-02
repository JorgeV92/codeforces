#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n;
        std::vector<int> a(n);
        long long sum = 0;
        for (int &x : a) { std::cin >> x; sum += x; }
        bool ok = false;
        for (int i = 1; i + 1 < n; i++) ok |= a[i] > 1;
        if (ok) std::cout << sum - 1 << '\n';
        else if (a[0] > 1 || a.back() > 1) std::cout << a[0] + a.back() - 1 << '\n';
        else std::cout << -1 << '\n';
    }
    return 0;
}
