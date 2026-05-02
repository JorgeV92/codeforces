#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <numeric>
using namespace std;

namespace jorgee {

struct Fenwick {
    int n; vector<int64_t> bit;
    Fenwick(int n_) : n(n_), bit(n_+1, 0) {}
    void add(int pos, int64_t val)  {
        pos++;
        while (pos <= n) {
            bit[pos] += val;
            pos += pos & -pos;
        }
    }
    int64_t sumPrefix(int r) const {
        int64_t sum = 0;
        while (r > 0) {
            sum += bit[r];
            r -= r & -r;
        }
        return sum;
    }
    int64_t sumRange(int l, int r) const {
        return sumPrefix(r) - sumPrefix(l);
    }
};
} // namespace jorgee

void run() {
    int n; cin >> n;
    vector<int64_t> a(n+1); for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int64_t> pref(n+1, 0); 
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            pref[i] = pref[i-1] + a[i];
        } else {
            pref[i] = pref[i-1] - a[i];
        }
    }
    auto vals = pref;
    {
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
    }
    auto getIndex = [&](int64_t x) {
        return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin());
    };
    jorgee::Fenwick evenTree(vals.size());
    jorgee::Fenwick oddTree(vals.size());

    int64_t ans = 0;
    evenTree.add(getIndex(pref[0]), 1);
    int64_t even_cnt = 1;
    int64_t odd_cnt = 0;
    for (int r = 1; r <= n; r++) {
        int id = getIndex(pref[r]);
        if (r % 2 == 1) {
            ans += evenTree.sumPrefix(id);
        } else {
            ans += odd_cnt - oddTree.sumPrefix(id+1);
        }
        if (r % 2 == 0 ) {
            evenTree.add(id, 1);
            even_cnt++;
        } else {
            oddTree.add(id, 1);
            odd_cnt++;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        run();
    }
    return 0;
}