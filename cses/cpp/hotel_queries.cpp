#include <iostream>
#include <vector>
#include <algorithm>
int n, m;
std::vector<int> seg;
void build(int node, int l, int r, const std::vector<int>& h) {
  if (l == r) { seg[node] = h[l]; return; }
  int mid = (l+r) / 2;
  build(node<<1, l, mid, h);
  build(node<<1|1, mid+1, r, h);
  seg[node] = std::max(seg[node<<1], seg[node<<1|1]);
}
int query(int node, int l, int r, int x) {
  if (seg[node] < x) return 0;
  if (l == r) { seg[node] -= x; return l+1; } 
  int mid = (l+r) / 2;
  int ans{};
  if (seg[node<<1] >= x) { ans = query(node<<1, l , mid, x); } 
  else { ans = query(node<<1|1, mid+1, r, x); }
  seg[node] = std::max(seg[node<<1], seg[node<<1|1]);
  return ans;
}
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  std::cin >> n >> m;
  std::vector<int> h(n); for (int& x : h) std::cin >> x;
  seg.resize(4*n);
  build(1, 0, n-1, h);
  for (int i = 0; i < m; i++) {
    int x; std::cin >> x;
    std::cout << query(1, 0, n-1, x) << ' ';
  }
  std::cout << '\n';
  return 0;
}
