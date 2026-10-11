#include <iostream>
#include <vector>
#include <algorithm>
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n;
        int k = 0;
        while ((1<<k) <= n) k++;
        int P = 1<<k, half = P >> 1;
        std::vector<int> path;
        if (half == 1) {
            path = {0,1};
        } else {
            path.push_back(0);
            for (int x = 2; x < half; x++) path.push_back(x);
            path.push_back(1);
            path.push_back(half+1);
            for (int x = half; x < P; x++) 
                if (x != half + 1) path.push_back(x);
        }
        std::vector<int> a;
        a.push_back(0);
        for (int i = 1; i < (int)path.size(); i++) {
            a.push_back(path[i-1] ^ path[i]);
            a.push_back(0);
        }
        std::cout << a.size() << '\n';
        for (int i = 0; i < (int)a.size(); i++) 
            std::cout << a[i] << ' ';
        std::cout << '\n';
    }

    return 0;
}