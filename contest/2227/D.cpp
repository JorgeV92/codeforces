#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdint>
using namespace std;

namespace jorgee {

struct fastset {
    using ull = unsigned long long;
    static constexpr int B = 64;
    int n;
    vector<vector<ull>> tree;
    fastset() : n(0) {}
    fastset(int n_) { init(n_); }
    void init(int n_) {
        n = n_; tree.clear(); int len = n;
        while (true) {
            int blocks = (len + B - 1) / B;
            tree.push_back(vector<ull>(blocks, 0));
            if (blocks == 1) break;
            len = blocks;
        }
    }
    bool contains(int x) const {
        if (x < 0 || x >= n) return false;
        return (tree[0][x/B] >> (x % B)) & 1ull;
    }
    void insert(int x) {
        if (x < 0 || x >= n) return;
        for (int i = 0; i < (int)tree.size(); i++) {
            tree[i][x/B] |= 1ull << (x % B);
            x /= B;
        }
    }
    void erase(int x) {
        if (x < 0 || x >= n) return;
        for (int i = 0; i < (int)tree.size(); i++) {
            int block = x/B;
            int bit = x % B;
            tree[i][block] &= ~(1ull << bit);
            if (tree[i][block] != 0) break;
            x /= B;
        }
    }
    int next_ge(int x) const {
        if (x < 0) x = 0;
        if (x >= n) return n;
        int i = 0;
        int idx = x;
        while (true) {
            if (i >= (int)tree.size()) return n;
            int block = idx / B;
            int bit = idx % B;
            if (block >= (int)tree[i].size()) return n;
            ull mask = tree[i][block] & (~0ULL << bit);
            if (mask == 0) {
                i++; idx = block + 1;
            } else {
                int offset = __builtin_ctzll(mask);
                idx = block * B + offset;
                if (i == 0) {
                    return idx < n ? idx : n;
                }
                idx *= B;
                i--;
            }
        }
    }
};

struct Mex {
    int max_value;
    fastset missing;
    vector<int> cnt;

    Mex() : max_value(0) {}
    Mex(int x) { init(x); }
    void init(int m_) {
        max_value = m_;
        missing.init(max_value+1);
        cnt.assign(max_value + 1, 0);
        for (int x = 0; x <= max_value; x++) {
            missing.insert(x);
        }
    }
    void add(int x) {
        if (x < 0 || x > max_value) return;
        cnt[x]++;
        if (cnt[x] == 1) missing.erase(x);
    }
    void remove(int x) {
        if (x < 0 || x > max_value) return;
        cnt[x]--;
        if (cnt[x] == 0) missing.insert(x);
    }
    int get() const {
        return missing.next_ge(0);
    }
};

} // namespace jorgee

void solve() {
    int n; cin >> n;
    int m = 2 * n;
    vector<int> a(m); for (int i = 0; i < m; i++) {cin >> a[i];}
    jorgee::Mex mex(n);
    int ans = 0;
    // odd len
    for (int cen = 0; cen < m; cen++) {
        vector<int> used;
        mex.add(a[cen]);
        used.push_back(a[cen]);
        for (int ra = 1; cen - ra >= 0 && cen + ra < m; ra++) {
            int l = cen - ra;
            int r = cen + ra;
            if (a[l] != a[r]) break;
            mex.add(a[l]);
            used.push_back(a[l]);
        }
        ans = max(ans, mex.get());
        for (int x : used) {
            mex.remove(x);
        }
    }
    // even len
    for (int cen = 0; cen + 1 < m; cen++) {
        vector<int> used;
        for (int ra = 0; cen - ra >= 0 && cen+1+ra < m; ra++) {
            int l = cen - ra;
            int r = cen + ra + 1;
            if (a[l] != a[r]) break;
            mex.add(a[l]);
            used.push_back(a[l]);
        }
        ans = max(ans, mex.get());
        for (int x : used) {
            mex.remove(x);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}