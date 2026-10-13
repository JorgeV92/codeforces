#include <iostream>
#include <vector>
#include <algorithm>
using i64 = long long;
const int KMAX = 1000;
i64 S[KMAX+1];
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    std::vector<i64> sig(KMAX+1);
    for (int d = 1; d <= KMAX; ++d) {
        for (int m = d; m <= KMAX; m += d) {
            sig[m] += d;
        }
    }
    for (int i = 1; i <= KMAX; i++) S[i] = S[i-1] + sig[i];
    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n;
        int k = int(std::lower_bound(S, S+KMAX+1, n) - S);
        std::vector<int> c(k+1);
        int rem = n;
        for (int i = k; i >= 1; i--) {
            c[i] = std::min(k/i, rem/i);
            rem -= i * c[i];
        }
        std::cout << k << '\n';
        int label = 1;
        std::vector<int> out;
        for (int i = 1; i <= k; i++) 
            for (int j = 0; j < c[i]; j++, label++) 
                for (int r = 0; r < i; r++) 
                    out.push_back(label);
        for (auto x : out) std::cout << x << ' ';
        std::cout << '\n';
    }
    return 0;
}