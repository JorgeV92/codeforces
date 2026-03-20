#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int64_t x, y, k;
        cin >> x >> y >> k;
        int64_t need = k * (y+1) - 1;
        cout << (need + x -2) / (x-1) + k << '\n'; 
    }
    return 0;
}   