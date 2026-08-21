#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    for (int i = 1; i <= n; i += 2) {
      cout << i + 1 << ' ' << i << ' '; 
    }
    cout << '\n';
  }
  return 0;
}
