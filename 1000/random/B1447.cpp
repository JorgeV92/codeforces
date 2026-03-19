#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;
        N *= M;
        bool flip =0;
        vector<int> A(N);
        for (auto& a : A) {
            cin >> a;
            flip ^= (a < 0);
            a = abs(a);
        }
        if (flip) {
            *min_element(A.begin(), A.end()) *= -1;
        }
        cout << accumulate(A.begin(), A.end(), 0) << '\n';
    }
    return 0;
}