#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

const int inf = 1e9;


struct Node {
    int l = 0, r = 0;
    int mn = inf;
};

vector<Node> seg(1);

int update(int old, int l, int r, int pos, int val) {
    int cur = seg.size();
    seg.push_back(seg[old]);
    if (l == r) {
        seg[cur].mn = min(seg[cur].mn, val);
        return cur;
    }
    int mid = (l+r) / 2;
    if (pos <= mid) {
        seg[cur].l = update(seg[old].l, l, mid, pos, val); 
    } else {
        seg[cur].r = update(seg[old].r, mid+1, r, pos ,val);
    }
    int L = seg[cur].l ? seg[seg[cur].l].mn : inf;
    int R = seg[cur].r ? seg[seg[cur].r].mn : inf;
    seg[cur].mn = min(L, R);
    return cur;
}

int query(int node, int l, int r, int ql, int qr) {
    if (node == 0 || qr < l || r < ql) return inf;
    if (ql <= l && r <= qr) return seg[node].mn;
    int mid = (l+r)/2;
    return min(query(seg[node].l, l, mid, ql, qr), query(seg[node].r, mid+1, r, ql, qr));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, m; cin >> n >> m;
    vector<ll> a(n+1);
    vector<ll> vals;
    vals.reserve(n);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        vals.push_back(a[i]);
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    vector<int> last(vals.size(), 0);
    vector<int> root(n+1);
    seg.reserve((ll)n * 21 + 5);

    for (int i = 1; i <= n; ++i) {
        root[i] = root[i-1];
        int id  = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
        int p = last[id];
        if (p != 0) {
            root[i] = update(root[i], 1, n , p, i-p);
        }
        last[id] = i;
    }
    while (m--) {
        int l, r; cin >> l >> r;
        int ans = query(root[r], 1, n, l, n);
    
        if (ans == inf) cout << -1 << '\n';
        else cout << ans << '\n';
    }

    return 0;
}