#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdint>
#include <cstring>
using pii = std::pair<int,int>;
const int maxn = 2e5;

int64_t D;
int64_t H[maxn];
const int maxv = maxn;
int N, V;
int64_t vals[maxv];

template <class T> struct bit {
  T b[maxv];

  T getmax(int a) {
    T res{};
    for (int i = a; i > 0; i -= i & (-i)) {
      res = std::max(res, b[i]);
    }
    return res;
  }

  void setmax(int a, T v) {
    a++;
    for (int i = a; i <= V; i += i & (-i)) {
      b[i] = std::max(b[i], v);
    }
  }

  bit() { memset(b, 0, sizeof(b)); }
};

bit<pii> bt[2];
int prv[maxn];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  std::cin >> N >> D; for (int i = 0; i < N; ++i) std::cin >> H[i];
  V = 0;
  for (int i = 0; i < N; ++i) {
    vals[V++] = H[i];
  }
  std::sort(vals, vals+V);
  V = std::unique(vals, vals+V) -vals;

  pii res{};
  for (int i = N-1; i >= 0; --i) {
    auto len1 = bt[0].getmax(std::upper_bound(vals, vals+V, H[i]-D)-vals);
    auto len2 = bt[1].getmax(V - (std::lower_bound(vals, vals+V, H[i] + D) -vals));
    auto len = std::max(len1, len2);
    int ind = std::lower_bound(vals, vals+V, H[i]) - vals;
    prv[i+1] = len.second;
    len.first++;
    len.second = i + 1;
    res = max(res, len);
    bt[0].setmax(ind, len);
    bt[1].setmax(V-1-ind, len);
  }
  std::cout << res.first << '\n';
  for (int cur = res.second; cur; cur = prv[cur]) {
    std::cout << cur << ' ';
  }
  std::cout << '\n';
  return 0;
}


