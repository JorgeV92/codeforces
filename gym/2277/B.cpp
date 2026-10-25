#include <algorithm>
#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int N; std::cin >> N;
        std::vector<int> A(N);
        for (int &x : A) std::cin >> x;
        int mn = *std::min_element(A.begin(), A.end());
        std::cout << (mn < N ? N : 0) << '\n';
    }
    return 0;
}
