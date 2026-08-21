#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
pair<int,vector<int>> bfs(int s, const vector<vector<int>>& g) {
    int n = g.size();
    vector<int> dist(n,-1);
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    int far = s;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (dist[v] > dist[far]) far = v;
        for (int to : g[v]) {
            if (dist[to] == -1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }
    return {far, ::move(dist)};
}
vector<int> process(int root, int x, const vector<vector<int>>& g) {
    int n = g.size();
    vector<int> dist(n,-1), par(n,-1), order;
    queue<int> q;
    dist[root] = 0;
    q.push(root);
    int max_depth = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        order.push_back(v);
        max_depth = max(max_depth, dist[v]);
        for (int to : g[v]) {
            if (v == root && to == x) {
                continue;
            }
            if (dist[to] == -1) {
                dist[to] = dist[v] + 1;
                par[to] = v;
                q.push(to);
            }
        }
    }
    vector<char> good(n,false);
    for (int v : order) {
        if (dist[v] == max_depth) good[v] = true;
    }
    for (int i = (int)order.size()-1; i >= 0; i--) {
        int v = order[i];
        if (good[v] && par[v] != -1) {
            good[par[v]] = true;
        }
    }
    vector<int> possible;
    for (int v : order) {
        if (!good[v]) continue;
        int gc = 0;
        for (int to : g[v]) {
            if (par[to] == v && good[to]) ++gc;
        }
        if (gc != 1) possible.push_back(dist[v]);
    }
    sort(possible.begin(), possible.end());
    possible.erase(unique(possible.begin(), possible.end()), possible.end());
    return possible;
}
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<vector<int>> g(n);
        for (int i = 0 ; i  < n-1; ++i) {
            int u, v; cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        auto [e1, _] = bfs(0, g);
        auto [e2, dist1] = bfs(e1, g);
        auto [dummy, dist2] = bfs(e2, g);
        int diam = dist1[e2];
        int x = -1;
        int y = -1;
        for (int v = 0; v < n; ++v) {
            if (dist1[v] + dist2[v] != diam) continue;
            if (dist1[v] == diam/2) x = v;
            if (dist1[v] == diam / 2 + 1) y = v;
        }
        vector<int> left = process(x, y, g);
        vector<int> right = process(y, x, g);
        vector<char> beautiful(n+1,false);
        for (int p : left) {
            for (int q : right) {
                beautiful[p+q+1] = true;
            } 
        }
        int cnt = 0;
        for (int k = 1; k <= n; k++) {
            if (beautiful[k]) cnt++;
        }
        cout << cnt << ' ';
        for (int k = 1; k <= n; k++) {
            if (beautiful[k]) cout << k << ' ';
        }
        cout << '\n';
    }
    return 0;
}