#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stack>
#include <functional>
#include <bitset>
using namespace std;

const int maxn = 3010;

struct DSU {
    vector<int> p, sz;
    int comp;
    DSU(int n) {
        p.resize(n); 
        sz.assign(n,1);
        iota(p.begin(), p.end(), 0);
        comp = n;
    }
    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (sz[x] < sz[y]) swap(x,y);
        p[y]= x, sz[x] += sz[y];
        comp--;
        return true;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<int> U(m), V(m);
    for (int e= 0; e < m; ++e) {
        cin >> U[e] >> V[e];
        --U[e]; --V[e];
    }
    DSU d(n);
    vector<vector<pair<int,int>>> tree(n);
    vector<int> ext; 
    for (int e = 0; e < m; ++e) {
        int u = U[e], v = V[e];
        if (d.unite(u,v)) {
            tree[u].push_back({v, e});
            tree[v].push_back({u,e});
        } else {
            ext.push_back(e);
        }
    }
    int k = ext.size();
    vector<int> par(n,-1), par_edge(n,-1);
    par[0] = 0;

    function<void(int)> dfs = [&](int v) {
        for (auto [to, id] : tree[v]) {
            if (par[to] == -1) {
                par[to] = v;
                par_edge[to] = id;
                dfs(to);
            }
        }
    }; dfs(0);

    vector<bitset<maxn>> ba(k);
    for (int i = 0; i < k; i++) {
        int e = ext[i];
        int u = U[e], v = V[e];
        ba[i].flip(e);
        int x = u;
        while (x != 0) {
            ba[i].flip(par_edge[x]);
            x = par[x];
        }
        x = v;
        while (x != 0) {
            ba[i].flip(par_edge[x]);
            x = par[x];
        }
    }

    for (int mask = 1; mask < (1 << k); ++mask) {
        bitset<maxn> re; 
        for (int i = 0; i < k; ++i) {
            if (mask & (1 << i)) 
                re ^= ba[i];
        }
        DSU d2(n);
        for (int e = 0; e < m; ++e) {
            if (re[e]) continue;
            d2.unite(U[e], V[e]);
        }
        if (d2.comp == 1) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";

}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        // O(2^k * m * alpha(n))
        solve();
    }
    return 0;
}