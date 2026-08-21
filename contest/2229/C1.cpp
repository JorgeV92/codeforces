#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> pos; pos.reserve(n);
    bool flip = false;
    for (int i = n - 1; i >= 0; --i) {
      if ((a[i] > 0) != flip) {
        pos.push_back(i);
        flip = !flip;
      }
    }
    cout << pos.size() << '\n';
    for (int i = 0; i < (int)pos.size(); ++i) {
      cout << pos[i] + 1 << ' ';
    }
    cout << '\n';
  }
  return 0;
}
