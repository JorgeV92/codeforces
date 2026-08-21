#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n;
       std::unordered_map<int,int> freq;
       int64_t sum = 0;
       int64_t max_freq = 0;
       int64_t max_val = 0;
       for (int i = 0; i < n; ++i) {
            int x; std::cin >> x;
            sum += x;
            freq[x]++;
            if (freq[x] > max_freq) {
                max_freq = freq[x];
                max_val = x;
            }
       }
       int64_t others = n - max_freq;
       int64_t majority = others + 2;
       int64_t ans = (sum - max_val * max_freq) + max_val * std::min(max_freq, majority); 
       std::cout << ans << '\n';

    }
    return 0;
}