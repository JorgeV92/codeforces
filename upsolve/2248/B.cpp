#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    int N, M; std::cin >> N >> M;
    std::vector<int> A(N); for (int i = 0; i < N; ++i) std::cin >> A[i];
    std::vector<int> B(M); for (int i = 0; i < M; ++i) std::cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    if (N < 2*M) {
      std::cout << "NO\n";
      continue;
    } 
    bool good = true;
    for (int  i = 0; i < M; ++i) {
      int l = A[i];
      int r = A[N-M+i];
      if (!(l < B[i] && B[i] < r)) {
        good = false;
        break;
      }
    }
    std::cout << (good ? "YES" : "NO") << '\n';
  }
  return 0;
}
