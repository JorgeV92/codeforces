#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(nullptr);
    auto titan = [&]() -> void {
        int T; std::cin >> T;
        while (T--) {
            int n; std::cin >> n;
            std::vector<int> a(n); for (int& x : a) std::cin >> x;
            auto it1 = std::max_element(a.begin(), a.end());
            auto it2 = std::min_element(a.begin(), a.end()); 
            if (*it1 == *it2) {
                std::cout << "NO\n"; 
                continue;
            }
            int p1 = it1 - a.begin();
            int p2 = it2 - a.begin();
            std::cout << "YES\n";
            for (int i = 0; i < n; i++) {
                if (i == p1) continue;
                std::cout << i+1 << " ";
                if (a[i] == a[p1]) {
                    std::cout << p2+1 << '\n';
                } else {
                    std::cout << p1 +1 << "\n";
                }
            }
        }
    }; titan();
    return 0;
}