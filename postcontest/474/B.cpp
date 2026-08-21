#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<int> a(n); for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::vector<std::pair<int,int>> seg{{1, a[0]}};
  for (int i = 1; i < n; i++) {
    seg.push_back({seg.back().second+1, seg.back().second + a[i]});
  }
  /*
  for (auto s : seg) {
    std::cout << s.first << ' ' << s.second << '\n';
  }
  std::cout << "---------------------------\n";
  */
  int M; std::cin >> M;
  for (int i = 0; i < M; ++i) {
    int q; std::cin  >> q;
    int j = std::lower_bound(seg.begin(), seg.end(), q,
                             [&](const auto& a, int x) {
                                return a.second< x; 
                             }) - seg.begin(); 
    std::cout << j+1 << '\n';
  }
  return 0;
}

/*
* 
*  [1 ,2] - [3, 9] - [10, 12]
*/

/*
  
  int A[MAXN];
  for (int i = 0; i < N; i++) std::cin >> A[i];
  for (int i = 0 i < n; ++i) A[i+1] += A[i];
  int M; std::cin >> M;
  for (int i = 0; i < M; ++i) {
    int q; std::cin >> q; 
    std::cout << std::lower_bound(A, A+N, q) - A + 1 << '\n';
  }

*/
