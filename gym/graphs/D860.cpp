#include <iostream>
#include <vector>
using namespace std;
vector<bool> vis;
vector<vector<int>> g;
vector<vector<int>> ans; 

bool dfs(int x, int f) {
    vis[x] = true;
    vector<int> curr;
    for (int y : g[x]) {
        if (y != f) {
            if (vis[y]) {
                // Non-tree edge
                if (x < y) {
                    curr.push_back(y);
                }
            } else {
                // if child return true
                // it did not use edge x-y
                // so x may use it
                if (dfs(y, x)) { 
                    curr.push_back(y);
                }
            }
        }
    }
    for (int i = 0; i+1 < (int)curr.size(); i += 2) {
        ans.push_back({curr[i], x, curr[i+1]});
    }
    if (curr.size() % 2==0) {
        return true; // everyting was paired we dont need egde x-f
    }
    if (f != -1) { // one edge remains 
        ans.push_back({curr.back(), x , f});
    }
    return false; // parent not used
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;
    g.resize(n);
    vis.resize(n);

    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) dfs(i,-1);
    }

    cout << ans.size() << '\n';
    for (auto& a : ans) {
        cout << a[0]+1 << ' ' << a[1]+1 << ' ' << a[2]+1 << '\n';
    }

    return 0;
}