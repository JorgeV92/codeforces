#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, B; cin >> N >> B;
    vector<int> A(N); for (int i = 0; i < N; i++) { cin >> A[i]; }
    vector<int> c;
    int odd = 0, even = 0;
    for (int i = 0; i+1 < N; i++) {
        if (A[i] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
        if (odd == even) {
            c.push_back(abs(A[i] - A[i+1]));
        }
    }
    sort(c.begin(), c.end());
    int ans = 0;
    for (int x : c) {
        if (B >= x) {
            ans++;
            B -= x;
        } else {
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}