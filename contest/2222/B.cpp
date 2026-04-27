#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cstdint>
using namespace std;

int main() {    
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;
        array<vector<int>, 2> A;
        A[0].reserve((N+1)/2);
        A[1].reserve((N)/2);
        for (int i = 0; i < N; i++) {
            int x; cin >> x;
            A[i&1].push_back(x);
        }
        array<int,2> cnt{0,0};
        for (int j = 0; j < M; j++) {
            int x; cin >> x; 
            x--;
            cnt[x&1]++;
        }
        int64_t ans = 0;
        for (int z = 0; z < 2; z++) {
            sort(A[z].begin(), A[z].end());
            if (cnt[z] > 0) {
                cnt[z]--;
                A[z].pop_back();
                while (cnt[z] && !A[z].empty() && A[z].back() > 0) {
                    cnt[z]--;
                    A[z].pop_back();
                }
            }
            for (auto a : A[z]) ans += a;
        }
        cout<< ans << '\n';
    }
    return 0;       
}