#pragma once 

#include <vector>

// Bellman-Ford
// Shortest Path w/ negative weights
const long long INF = 1e18;

template<int SZ> struct BellmanFord {
    int n;
    vector<int> adj[SZ];
    long long dist[SZ];
    vector<pair<pair<int,int>, int>> ed;
    void ae(int u, int v, int w) {
        adj[u].push_back(v), ed.push_back({{u,v}, w});
    }
    void genBad(int x) {
        if (dist[x] == -INF) return;
        dist[x] = -INF;
        for (auto y : adj[x]) genBad(y);
    }
    void init(int _n, int s) {
        n = _n; for (int i = 0; i < n; i++) dist[i] = INF;
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

// sample of a bellmaford
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    const int INF = 1e9;
    vector<tuple<int,int,int>> ed;
    for (auto& e : flights) {
        ed.emplace_back(e[0], e[1], e[1]);
    }
    vector<int> dist(n, INF);
    dist[src] = 0;
    for (int i = 0; i <= k; i++) {
        vector<int> ndist = dist;
        for (auto& e : ed) {
            int u, v, w;
            tie(u, v, w) = e;
            if (dist[u] < INF) 
                ndist[v] = min(ndist[v], dist[u] + w);
        } 
        dist = ndist;
    }
    return dist[dst] == INF ? -1 : dist[dst];
}