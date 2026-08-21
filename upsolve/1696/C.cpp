#include <iostream>
#include <vector>
#include <cstdint>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    int N, M; std::cin >> N >> M;
    std::vector<int> A(N);
    for (auto& a : A) std::cin >> a;
    int K; std::cin >> K;
    std::vector<int> B(K);
    for (auto& b : B) std::cin >> b;

    auto cononicalize = [&](const std::vector<int>& a) {
      std::vector<std::pair<int,int64_t>> r;
      r.reserve(a.size());
      for (int v : a) {
        int64_t cnt = 1;
        while (v % M == 0) {
          v /= M;
          cnt *= M;
        }
        if (!r.empty() && r.back().first == v) r.back().second += cnt;
        else r.push_back({v, cnt});
      }
      return r;
    };

    std::cout << (cononicalize(A) == cononicalize(B) ? "Yes" : "No") << '\n';

  }
  return 0;
}
