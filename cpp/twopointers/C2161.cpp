#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdint>

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    auto jorgee = [&]() -> void {
        int T; std::cin >> T;
        while (T--) {
            int N, X; std::cin >> N >> X;
            std::vector<int> A(N); for (int i =0 ; i < N; i++) std::cin >> A[i];
            std::sort(A.begin(), A.end());
            int64_t S = std::accumulate(A.begin(), A.end(), 0LL);
            int t = S/X;
            int64_t ans = 0;
            for (int i = 0; i < t; i++) {
                ans += A[N-i-1];
            }
            std::cout << ans << "\n";
            int l = 0, r = N;
            int64_t cur = 0;
            while (l < r) {
                if ((cur + A[r-1]) / X > cur / X) {
                    std::cout << A[r-1] << ' ';
                    cur += A[r-1];
                    r--;
                } else {
                    std::cout << A[l] << ' ';
                    cur += A[l];
                    l++;
                }
            }
            std::cout << "\n";
        }
    }; jorgee();
    return 0;
}