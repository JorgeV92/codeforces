#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdint>
#include <map>
using namespace std;
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    vector<int64_t> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    int  ans = n;
    for (int i = 0; i < n;) {
      int j = i;
      while (j < n && a[i] == a[j]) j++;
      int l{}, r{}; 
      l = i;
      r = n-j;
      ans = min(ans, max(l,r));
      i = j;
    }
    cout << ans << '\n';
  }
  return 0;
}
