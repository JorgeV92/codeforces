#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int T; cin >> T;
  while (T--) {
    int n, c; cin >> n >> c;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    
    int mn = 0;
    bool shuffle = false;
    bool good = true;
    for (int i = 0; i < n; i++) {
      if (a[i] < b[i]) {
       shuffle = true;
      }
      mn += a[i] - b[i];
    }
    if (shuffle) {
      mn += c;
        
      sort(a.begin(), a.end());
      sort(b.begin(), b.end());
      for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) {
          good = false;
          break;
        }
      }
    } 
    cout << (good ? mn : -1) << '\n';
  }
  
  return 0;
}
