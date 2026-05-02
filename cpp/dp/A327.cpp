#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    auto jorgee = [&]() -> void {
        int N; std::cin >> N; 
        std::vector<int> a(N); for (int& x : a) std::cin >>x;
        int ones = std::count(a.begin(), a.end(), 1);
        int mx = -1e9;
        int t = 0;
        for (int i = 0; i < N; i++) {
            int g = (a[i] == 0 ? 1 : -1);
            t = std::max(g, t + g);
            mx = std::max(mx,  t);
        }   
        std::cout << (ones+mx) << "\n";
    }; jorgee();
    return 0;
}