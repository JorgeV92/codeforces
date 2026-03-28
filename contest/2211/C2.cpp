#include <iostream>
#include <vector>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (int i = 0; i < n; i++) std::cin >> b[i];
    bool valid = true;
    std::vector<int> aa;
    std::vector<int> bb;
    for (int r = 0;  r < k; r++) {
        bool u = true;
        int f = a[r];
        for (int i = r; i < n; i += k) {
            if (a[i] != f) {
                u = false;
                break;
            }
        }
        if (!u) {
            for (int i= r; i < n; i += k) {
                if (b[i] != -1 && b[i] != a[i]) {
                    valid = false;
                }
            }
        } else {
            aa.push_back(f);
            int bv = -1;
            for (int i = r; i < n; i += k) {
                if (b[i] != -1) {
                    if (bv == -1) {
                        bv = b[i];
                    } else if (bv != b[i]){
                        valid = false;
                    }
                } 
            }
            if (bv != -1) {
                bb.push_back(bv);
            } 
        }
    }
    if (!valid) {std::cout << "NO\n";return;}
    std::vector<int> cnt(n+1);
    for (int x : aa) cnt[x]++;
    for (int x : bb) {
        cnt[x]--;
        if (cnt[x] < 0) {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}