#include <iostream>
#include <vector>

void solve(){
    int n, r, b;
    std::cin >> n >> r >> b;

    int v = r;
    for (int i = 0; i <= b; i++) {
        for (int j =0; j < v / (b-i+1); j++) {
            std::cout << "R";
        }
        v -= v /(b-i+1);
        if (i < b) {
            std::cout << "B";
        }
    }
    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}