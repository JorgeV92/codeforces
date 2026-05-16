#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;
        vector<int> A(M);
        for (int i = 0; i < M; i++) {
            cin >> A[i];
            A[i]--;
        }
        sort(A.begin(), A.end());
        vector<int> B(M);
        for (int i = 0; i < M-1; i++) {
            B[i] = A[i+1] - A[i] - 1;
        }
        B[M-1] = A[0] + N - A[M-1] - 1;
        sort(B.begin(), B.end(), greater<int>());
        int s = 0;
        for (int i =0 ; i < M; ++i) {
            if (B[i] >= 4*i+3) {
                s += B[i] - (4*i+1);
            } else if (B[i] >= 4*i+1) {
                s++;
            }
        }
        cout << N - s << '\n';
    }
    return 0;   
}