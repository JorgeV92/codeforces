#include <iostream>
#include <vector>
#include <algorithm>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    int N, K; std::cin >> N >> K;
    int b = 0;
    while ((1 << (b+1)) <= N) b++;
    K ^= N;
    if (K >= (1 << (b+1))) {
      std::cout << "NO\n";
      continue;
    }
    std::vector<int> ans; ans.reserve(N);
    if (K >= (1 << b)) {
      if (N == (1 << b)) {
        std::cout << "NO\n";
        continue;
      }
      K ^= N-1;
      ans.push_back(N-1);
    }
    if (K >0) {
      ans.push_back(K);
    }
    ans.push_back(0);
    std::vector<bool> used(N);
    for (auto v : ans) used[v] = true;
    for (int i = 0; i < N; ++i) if (!used[i]) ans.push_back(i);
    std::reverse(ans.begin(), ans.end());
    std::cout << "YES\n";
    for (int i = 0; i < N; ++i) {
      std::cout << ans[i] << " \n"[i+1==N];
    }

  }
  return 0;
}
