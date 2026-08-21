#include <iostream>
#include <vector>
#include <cstdint>
#include <stack>
using namespace std;

const int maxn = 20001;
int n, m;

struct Node {
  vector<int> adj;
  vector<int> rev_adj;
};

Node g[maxn];
stack<int> st;
bool vis[maxn];

int component[maxn];
vector<int> components[maxn];
int num_comps{0};

void dfs1(int x) {
  vis[x] = true;
  for (int y : g[x].adj) {
    if (!vis[y]) 
      dfs1(y);
  }
  st.push(x);
}

void dfs2(int x) {
  std::cout << x << " ";
  component[x] = num_comps;
  components[num_comps].push_back(x);
  vis[x] = true;
  for (int y : g[x].rev_adj) {
    if (!vis[y])
      dfs2(y);
  }
}

void kosaraju() {
  for (int i = 0; i < n; ++i) 
    if (!vis[i]) dfs1(i);

  for (int i = 0; i < n; i++)
    vis[i] = false;

  while (!st.empty()) {
    int v = st.top();
    st.pop();
    if (!vis[v]) {
      cout << "Component " << num_comps << ": ";
      dfs2(v);
      num_comps++;
      cout << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b; cin >> a >> b;
    g[a].adj.push_back(b);
    g[b].rev_adj.push_back(a);
  }
  kosaraju();
  cout << "Total number of components: " << num_comps << '\n';
  return 0;
}

