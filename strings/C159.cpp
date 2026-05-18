#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>
using namespace std;

struct FenwickTree {
    int n; vector<int> bit; FenwickTree(int _n) : n(_n) { bit.assign(n+1, 0); }
    FenwickTree() = default;
    FenwickTree(vector<int>& a) : FenwickTree(a.size()) { for (int i = 0; i < n; ++i) { add(i,a[i]); }}
    int sum(int r) {
        int ret = 0;
        for (; r > 0; r -= r & -r) 
            ret += bit[r];
        return ret;
    }
    void add(int idx, int delta) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += delta;
    }
    int kth(int k) {
        int idx = 0, step = 1;
        while ((step<<1) <= n) step<<=1;
        while (step>0) {
            int nxt = idx + step;
            if (nxt <= n && bit[nxt] < k) {
                idx = nxt;
                k -= bit[nxt];
            }
            step >>= 1;
        }
        return idx+1;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int k; cin>>k;;
    string s; cin>>s;
    string t{};
    t.reserve(k * s.size());
    for (int i = 0; i < k; ++i) 
        t += s;
    int m=t.size();
    array<FenwickTree, 26> fen;
    for (int c = 0; c < 26; ++c) {
        fen[c] = FenwickTree(m);
    }
    for (int i=1; i <= m; ++i) {
        int c = t[i-1]-'a';
        fen[c].add(i,1);
    }
    vector<bool> safe(m+1,true);
    int n; cin>>n;
    while (n--) {
        int p; char c;
        cin>>p>>c;
        int id = c-'a';
        int pos = fen[id].kth(p);
        fen[id].add(pos,-1);
        safe[pos]=false;
    }
    for (int i = 1; i <= m; ++i) {
        if (safe[i]) {
            cout<<t[i-1];
        }
    }
    cout<<'\n';
    return 0;
}   