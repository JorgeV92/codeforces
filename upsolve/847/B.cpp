#include <iostream>
#include <vector>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<std::vector<int>> res;
  std::vector<int> last;
  for (int i = 0; i < n; i++) {
    int x; std::cin >> x;
    int lo = 0, hi = (int)last.size();
    while (lo < hi)  {
      int mid = lo + (hi - lo) / 2;
      if (last[mid] < x) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    int id = lo;
    if (lo == (int)last.size()) {
      last.push_back(x);
      res.push_back({});
    } else {
      last[id] = x;
    }
    res[id].push_back(x);
  }

  for (const auto& seq : res) {
    for (int s : seq) {
      std::cout << s << ' ';
    }
      std::cout << '\n';
  }
  
  return 0;
}
