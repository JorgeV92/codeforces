#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n, m, x, y; std::cin >> n >> m >> x >> y;
        std::vector<int> a(x); for (int i = 0; i < x; ++i) std::cin >> a[i];
        std::vector<int> b(y); for (int i = 0; i < y; ++i) std::cin >> b[i];
        std::vector<int> A, B, C;

        int i = 0, j = 0;
        while (i < x && j < y) {
            if (a[i] == b[j]) {
                C.push_back(a[i]);
                i++; j++;
            } else if (a[i] < b[j]) {
                A.push_back(a[i]); 
                i++;
            } else {
                B.push_back(b[j]);
                j++;
            }
        }

        while (i < x) A.push_back(a[i++]);
        while (j < y) B.push_back(b[j++]);
        std::vector<int> D;

        int sa = std::min(n, (int)A.size());
        int sb = std::min(m, (int)B.size());

        for (int k = A.size() - sa; k < A.size(); k++) {
            D.push_back(A[k]);
        }
        
        for (int k = B.size() - sb; k < B.size(); k++) {
            D.push_back(B[k]);
        }

        for (int v : C) D.push_back(v);

        std::sort(D.begin(), D.end());
        long long ans = 0;
        int len = std::min(n+m-1, (int)D.size());
        for (int k  = D.size() - len; k < D.size(); k++) {
            ans += D[k];
        }
        std::cout << ans << '\n';
    }
    return 0;
}