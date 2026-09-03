#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
const int maxn = 3e5;
int tin[maxn];
int low[maxn];
vector<int> g[maxn];
vector<int> two_edge_components[maxn];
int timer = 0;
int scc = 0;
stack<int> st;

void dfs(int v, int f) {
    tin[v] = low[v] = ++timer;
    bool mult_edges = false;
    st.push(v);
    for (auto to : g[v]) {
        if (to == f && !mult_edges) {
            mult_edges = true;
            continue;
        }
        if (!tin[to]) {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
        } else {
            low[v] = min(low[v], tin[to]);
        }
    }
    if (low[v] == tin[v]) {
        while (st.top() != v) {
            two_edge_components[scc].push_back(st.top()); st.pop();
        }
        two_edge_components[scc++].push_back(st.top()); st.pop();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int v = 0; v < n; ++v) {
        if (tin[v] == 0) dfs(v,-1);
    }
    cout << scc << '\n';
    for (int i = 0; i < scc; i++) {
        cout << two_edge_components[i].size() << ' ';
        for (int node : two_edge_components[i]) cout << node << ' ';
        cout << '\n';
    }
    return 0;
}