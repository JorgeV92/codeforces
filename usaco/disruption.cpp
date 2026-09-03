#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

template<class T> using V = vector<T>;
using vi = vector<int>;

#define sz(x) int((x).size())
#define rsz resize
#define pb push_back

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)

#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

#define each(a,x) for (auto& a : x)

// LCA using binary jumping 
struct LCA {
    int N; V<vi> par, adj; vi depth;
    void init(int _N) { 
        N = _N; 
        int d = 1; while ((1<<d) < N) ++d;
        par.assign(d,vi(N)); adj.resize(N); depth.resize(N);
    }
    void ae(int x, int y) { adj[x].push_back(y), adj[y].push_back(x); }
    void gen(int R = 0) { par[0][R] = R; dfs(R); }
    void dfs(int x=0) {
        for (int i = 1; i < par.size(); i++) par[i][x] = par[i-1][par[i-1][x]];
        for (int y : adj[x]) if (y != par[0][x]) depth[y] = depth[par[0][y]=x]+1, dfs(y);
    }
    int jmp(int x, int d) {
        for (int i = 0; i < par.size(); i++) {
            if ((d>>i)&1) x = par[i][x];
        }
        return x;
    }
    int lca(int x, int y) {
        if (depth[x] < depth[y]) swap(x,y);
        x = jmp(x, depth[x]-depth[y]); if (x==y) return x;
        for (int i = par.size()-1; i >=0 ; i--) {
            int X = par[i][x], Y = par[i][y];
            if (X != Y) x = X, y = Y;
        }
        return par[0][x];
    }
    int dist(int x, int y) {
        return depth[x] + depth[y] - 2*depth[lca(x,y)];
    }
};

int n, m;
vi ans;
V<vi> add, rem;
LCA lca;

multiset<int> dfs(int x, int p) {
    multiset<int> s;
    for (int y : lca.adj[x]) {
        if (y != p) {
            auto ss = dfs(y, x);
            if (ss.size() > s.size()) swap(ss, s);
            s.insert(ss.begin(), ss.end());
        }
    }
    for (int y : add[x]) s.insert(y);
    for (int y : rem[x]) s.erase(s.find(y)), s.erase(s.find(y)); 
    if (s.size()) ans[x] = *s.begin(); 
    return s;
}

void solve() {
    cin >> n >> m;
    vector<pair<int,int>> edges;
    lca.init(n);
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        lca.ae(a, b);
        edges.push_back({a,b});
    }
    add.resize(n); rem.resize(n);
    lca.gen();
    while (m--) {
        int p, q, r; cin >> p >> q >> r;
        int l = lca.lca(--p,--q);
        add[p].push_back(r);
        add[q].push_back(r);
        rem[l].push_back(r);
    }
    ans.assign(n,-1);
    dfs(0,-1);
    for (auto& [a,b] : edges) {
        if (lca.depth[a] < lca.depth[b]) swap(a,b);
        cout << ans[a] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}