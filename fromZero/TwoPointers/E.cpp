#include <iostream>
#include <vector>
#include <set>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int n, k; std::cin >> n >> k;
    std::vector<int> a(n); for (int& x : a) std::cin >> x;
    std::multiset<int> lo, hi;
    int loTarget = (k+1) / 2;

    auto reblance = [&]() {
        while ((int)lo.size() > loTarget) {
            hi.insert(*prev(lo.end()));
            lo.erase(prev(lo.end()));
        }
        while ((int)lo.size() < loTarget && !hi.empty()) {
            lo.insert(*hi.begin());
            hi.erase(hi.begin());
        }
    };

    for (int i = 0; i < n; ++i) {
        if (lo.empty() || a[i] <= *prev(lo.end())) lo.insert(a[i]);
        else hi.insert(a[i]);
        if (i >= k) {
            auto it = lo.find(a[i-k]);
            if (it != lo.end()) lo.erase(it);
            else hi.erase(hi.find(a[i-k]));
        }
        reblance();
        if (i >= k-1) std::cout << *prev(lo.end()) << ' ';
    }
    std::cout << '\n';
    return 0;       
}