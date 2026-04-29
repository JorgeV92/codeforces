#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
std::vector<int> A;
bool canMakeMex(int k) {
   std::multiset<int> unused(A.begin(), A.end());
    for (int y = k-1; y >= 0; y--) {
        auto exact = unused.find(y);
        if (exact != unused.end()) {
            unused.erase(exact);
            continue;
        }
        auto bigger = unused.upper_bound(2*y);
        if (bigger == unused.end()) {
            return false;
        }
        unused.erase(bigger);
    }
    return true;
}
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int N; std::cin >> N; A.resize(N);
        for (int i = 0; i < N; i++) {
            std::cin >> A[i];
        }
        int lo = 0, hi = N;
        while (lo < hi) {
            int mid = (lo + hi + 1) >> 1;
            if (canMakeMex(mid)) {
                lo = mid;
            } else {
                hi = mid -1;
            }
        }
        std::cout << lo << '\n';
    }
    return 0;
}