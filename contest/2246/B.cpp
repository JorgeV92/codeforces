#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll =  long long;
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    if (n==1) {
      cout << 1 << '\n';
    } else if (n==2) {
      cout << -1 << '\n'; 
    } else {
      vector<ll> ans = {1, 2, 3};
      ll sum = 6;
      while (ans.size() < n) {
        ans.push_back(sum);
        sum *= 2;
      }
      for (ll x : ans) {
        cout << x << ' ';
      }
      cout << '\n';
    }
  }
  return 0;
}
