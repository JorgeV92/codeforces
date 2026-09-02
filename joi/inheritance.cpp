#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

template<typename T> using V = vector<T>;
#define vi V<int>

struct DSU {
    vi e; void init(int n) { e = vi(n,-1); }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool sameSet(int x, int y) { return get(x) == get(y); } 
    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return false; 
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y], e[y] = x;
        return true;
    }
};

struct edge {
    int u, v, w;
    int id;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, K; cin >> N >> M >> K;
    vector<edge> edges(M);
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        edges[i] = {u,v,w,i};
    }
    sort(edges.begin(), edges.end(), [&](const auto& a, const auto& b) {
        return a.w > b.w;
    });
    vector<DSU> d(K);
    for (auto& dsu : d) {
        dsu.init(N);
    }
    vector<int> ans(M);
    for (int i = 0; i < M; i++) {
        auto& e = edges[i];
        int lo = 1;
        int hi = K+1;
        while (lo < hi) {
            int mid = lo + (hi-lo) / 2;
            if (mid <= K && d[mid-1].sameSet(e.u, e.v)) {
                lo = mid+1;
            } else { hi = mid; }
        }
        if (lo <= K) { ans[e.id]=lo; d[lo-1].unite(e.u,e.v); }
        else { ans[e.id] = 0; }
    }
    for (int x : ans) {
        cout << x << '\n';
    }

    return 0;   
}