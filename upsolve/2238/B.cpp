#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    int64_t ans = 0;
    for (int b = 1; b <= n; ++b) {
      ans += 1LL * (n/b) * (n/b);
    }
    cout << ans << '\n';
  }
  return 0;
}
