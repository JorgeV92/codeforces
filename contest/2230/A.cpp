#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int64_t n,a,b; cin>>n>>a>>b;
        int64_t op = n/3;
        int64_t r = n%3;
        int64_t q = min(3*a,b);
        int64_t p = min(r*a, b);
        cout << op * q + p << '\n';
    }

    return 0;
}