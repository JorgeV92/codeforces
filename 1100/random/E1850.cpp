#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

void solve() {
    int64_t n, c;
    cin >> n >> c;
    std::vector<int64_t> s(n);
    int64_t sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        c -= s[i] * s[i];
        sum += s[i];
    }
    c /= 4;

    int64_t lo = 0, hi = 1E9;
    while (lo < hi) {
        int64_t x = (lo + hi) / 2;
        if (__int128_t(n) * x * x + __int128_t(sum) * x < c) {
            lo = x + 1;
        } else {
            hi = x;
        }
    }
    std::cout << lo << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}