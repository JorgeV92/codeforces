#include <cstdint>
#include <iostream>
#include <vector>
#include <bit>
#include <cstdint>
using namespace std;
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int T; cin >> T;
  while (T--) {
    int64_t n, k; cin >> n >> k;
    int64_t ans = 0;
    for (int64_t i = 0; i < 30; ++i) {
      int64_t num = min(n/(1LL<<i), k);
      ans += num;
      n -= num* (1LL<<i);
    }
    cout << ans << '\n';
  }
  return 0; 
}
