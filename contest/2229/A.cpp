#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int T; cin>>T;
  while (T--) {
    int n; cin >> n;
    vector<int> a(n); for (int i = 0; i < n; ++i) cin>>a[i];
    int mn = *min_element(a.begin() ,a.end()); 
    int mx = *max_element(a.begin(), a.end());
    int ans = (mx-mn + 1) / 2;
    cout<<ans<<'\n';
  }
  return 0;
}
