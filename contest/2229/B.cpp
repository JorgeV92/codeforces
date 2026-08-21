#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    for (int i = 0; i < n; ++i)
      cin >> b[i];
    int64_t sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += max(a[i], b[i]);
    }
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = max(ans, sum + min(a[i], b[i]));
    }
    cout << ans << '\n';
  }
  return 0;
}
