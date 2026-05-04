#include <iostream>
#include <vector>
#include <cstdint>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    auto jorgee = [&]() -> void {
        int T; cin >> T;
        while (T--) {
            int n; cin >> n;
            vector<int64_t> a(n); for (int i = 0; i < n; i++) cin >> a[i];
            int64_t k = 2;
            for (; k <= (1LL << 57); k *= 2) {
                set<int64_t> nu;
                for (int i = 0; i < n; i++) {
                    nu.insert(a[i]%k);
                }
                if (nu.size() == 2) break;
            }
            cout << k << "\n";
        }
    }; jorgee();    
    return 0;
}