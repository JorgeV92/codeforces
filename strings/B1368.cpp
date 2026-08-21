#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int64_t k; cin >> k;
    string s = "codeforces";
    vector<int64_t> cnt(10,1);

    auto prod = [&]() -> __int128_t {
        __int128_t p =1;
        for (auto x : cnt) {
            p *= x;
        }
        return p;
    };

    int i = 0;
    while (prod() < k) {
        cnt[i]++;
        i = (i + 1) % 10;
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < cnt[i]; ++j) {
            cout << s[i];
        }
    }
    cout << '\n';

    return 0;
}