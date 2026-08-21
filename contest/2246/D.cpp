#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    vector<ll> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
    auto get_f = [&](ll x) -> ll {
      if (x==0) return 0;
      ll b = 63 - __builtin_clzll(x);
      ll p = __builtin_popcountll(x);
      return b + p;
    };
    ll mn = -1;
    for (int k = 0; k < 22; k++) {
      ll curr = k;
      ll pw = 1LL << k;
      for (int i = 0; i < n; ++i) {
        ll m0 = (a[i] + pw - 1) / pw;
        ll best_cost = -1;
        for (ll m = m0; m <= m0+5; m++) {
          ll A_i = m * pw;
          ll cost = (A_i - a[i]) + get_f(m);
          if (best_cost == -1 || cost < best_cost) 
            best_cost = cost;
        }
        curr += best_cost;
      } 
      if (mn == -1 || curr < mn) 
        mn = curr;
    }
    cout << mn << '\n';
  }
  return 0;
}
