#include <iostream>
#include <vector>
#include <algorithm>
using i64 = long long;
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n, q; std::cin>>n>>q;
  std::vector<i64> a(n+1); for (int i=1; i<=n; i++) std::cin>>a[i];
  std::vector<i64> pref(n+1), w(n+1);
  for (int i=1;i<=n;i++) {
    pref[i] = pref[i-1]+a[i];
    w[i]=w[i-1]+(i64)i*a[i];
  }
  while (q--){
    int l,r; std::cin>>l>>r;
    i64 sum=pref[r]-pref[l-1];
    i64 wsum = w[r]-w[l-1];
    std::cout << wsum-(i64)(l-1)*sum<<'\n';
  }
  return 0; 
}
