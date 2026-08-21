#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int T; cin >> T;
  while (T--) {
    int n; cin>>n;
    vector<int> A(n); for(int& x : A) cin>>x;
    int64_t best_delta = 0;
    int p = -1;
    int64_t cur_delta = 0;
    for (int i = 0; i < n; ++i) {
      if (A[i]<0){
      } else {
        cur_delta -= 2 * abs(A[i]);
        if (cur_delta > best_delta) {
          best_delta = cur_delta;
          p = i;
        }
      }
      cur_delta += 2 * abs(A[i]);
    }

    vector<int>ops; ops.reserve(n);
    if (p >= 0) {
      bool flip = false;
      for (int i = p-1; i >= 0; --i) {
        if ((A[i] > 0) != flip) {
          ops.push_back(i);
          flip = !flip;
        }
      }
      ops.push_back(p);
    }
    cout<<ops.size()<<'\n';
    for (int i = 0; i < (int)ops.size(); ++i) {
      cout<<ops[i]+1<<' ';
    }
    cout<<'\n';
    
  }
  return 0;
}
