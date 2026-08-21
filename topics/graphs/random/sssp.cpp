#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 1e18;

template<int SZ> struct BellmanFord {
    int n;
    vector<int> adj[SZ];
    vector<pair<pair<int,int>, int>> ed;
    long long dist[SZ];
    void ae(int a, int b, int w) {
        adj[a].push_back(b); ed.push_back({{a, b}, w});
    }
    void genBad(int x) {
        if (dist[x] == -INF) return;
        dist[x] = -INF;
        for (auto y : adj[x]) genBad(y);
    }
    void init(int _n, int s) {
        n = _n; for (int i = 0; i < n; ++i ) dist[i] = INF;
        dist[s] = 0;
        for (int i = 0; i < n-1; ++i) 
            for (auto& e : ed) 
                if (dist[e.first.first] < INF)
                    dist[e.first.second] = min(dist[e.first.second], dist[e.first.first] + e.second);
        for (auto& e : ed) 
            if (dist[e.first.first] < INF && dist[e.first.second] > dist[e.first.first] + e.second)
                genBad(e.first.second);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, q, s; 
    while (cin >> n >> m >> q >> s) {
        BellmanFord<1003> bell;
        for (int i = 0; i < m; ++i) {
            int a, b, w; cin >> a >> b >> w;
            bell.ae(a, b, w);
        }
        bell.init(n, s);
        while (q--) {
            int a; cin >> a;
            if (bell.dist[a] == -INF) {
                cout << "-Infinity\n";
            } else if (bell.dist[a] == INF) {
                cout << "Impossible\n";
            } else {
                cout << bell.dist[a] << '\n';
            }
        }
        cout << '\n';
    }
    return 0;
}