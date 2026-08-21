#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n, m, k; std::cin >> n >> m >> k;
  std::vector<std::string> patterns(n); 
  std::unordered_map<std::string, int> id;
  for (int i = 0; i < n; ++i) {
    std::cin >> patterns[i];
    id[patterns[i]] = i;
  }
  std::vector<std::vector<int>> g(n);
  std::vector<int> ind(n);
  bool valid = true;
  for (int q = 0; q < m; ++q) {
    std::string s; std::cin >> s;
    int mt; std::cin >> mt;
    --mt;
    bool match = false;
    for (int mask = 0; mask < (1 << k); ++mask) {
      std::string cand = s;
      for (int i = 0; i < k; ++i) {
        if (mask & (1 << i)) {
          cand[i] = '_';
        }
      }
      auto it = id.find(cand);
      if (it == id.end()) continue;
      int match_pat = it->second;
      if (match_pat == mt) {
        match = true;
      }  else {
        g[mt].push_back(match_pat);
        ind[match_pat]++;
      }
    }

    if (!match) valid = false;
  }
  if (!valid) {
    std::cout << "NO\n";
    return 0;
  }

  std::queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (ind[i] == 0) q.push(i);
  }

  std::vector<int> order;
  order.reserve(n);

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    order.push_back(u);
    for (int v : g[u]) {
      if (!--ind[v]) q.push(v);
    }
  }

  if ((int)order.size() != n) {
    std::cout << "NO\n";
    return 0;
  }

  std::cout << "YES\n";
  for (int v : order) {
    std::cout << v + 1 << ' ';
  }
  std::cout << "\n";
  return 0;
}
