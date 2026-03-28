#include <iostream>
#include <vector>

void solve() {
    int n, k;
    std::cin >> n >>k;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (int i = 0; i < n; i++) std:: cin >> b[i];
    int L = n-k;
    int R = k;
    for (int i = 0; i < L; i++) {
        if (b[i] != -1 && b[i] != a[i]) {
            std::cout << "NO\n";
            return;
        }
    }
    for (int i = R; i < n; i++) {
        if (b[i] != -1 && b[i] != a[i]) {
            std::cout << "NO\n";
            return;
        }
    }
    if (L < R) {
        std::vector<bool> vis(n+1);
        for (int i = L; i < R; i++) {
            vis[a[i]] = true;
        }
        for (int i = L; i < R; i++) {
            if (b[i]!= - 1) {
                if (!vis[b[i]]) {
                    std::cout << "NO\n";
                    return;
                }
                vis[b[i]] = false;
            }
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