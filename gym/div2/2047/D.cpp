#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n; 
        std::vector<int> a(n); for (auto& x : a) std::cin >> x;
        int pos = std::min_element(a.begin(), a.end()) - a.begin();
        std::vector<int> back;
        for (int i = 0; i < pos; i++) back.push_back(a[i] + 1);
        std::vector<int> K;
        for (int i = pos; i < n; ++i) {
            while (!K.empty() && K.back() > a[i]) {
                back.push_back(K.back() + 1);
                K.pop_back();
            }
            K.push_back(a[i]);
        }
        if (!back.empty()) {
            int mn = *std::min_element(back.begin(), back.end());
            while (!K.empty() && K.back() > mn) {
                back.push_back(K.back() + 1);
                K.pop_back();
            }
        }
        std::sort(back.begin(), back.end());
        std::vector<int> ans = K;
        ans.insert(ans.end(), back.begin(), back.end());
        for (int i = 0; i < n; ++i) {
            std::cout << ans[i] << " \n"[i+1==n];
        }
    }
    return 0;
}