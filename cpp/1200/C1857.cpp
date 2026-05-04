#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    auto jorgee = [&]() -> void {
        int T; cin >> T;
        while (T--) {
            int n; cin>> n;
            vector<int> b(n*(n-1)/2); for (int i = 0; i < (n*(n-1)/2); i++) cin >> b[i];
            sort(b.begin(), b.end());
            vector<int> a;
            int pos = 0;
            for (int i = n-1; i >= 1; i--) {
                a.push_back(b[pos]);
                pos += i;
            }
            a.push_back(1000000000);
            for (int x : a) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }; jorgee();
    auto L = [&]() -> void {
        int T; cin >> T;
        while (T--) {
            int n; cin >> n;
            vector<int> a(n*(n-1)/2); 
            for (int i = 0; i < n*(n-1)/2; i++) {
                cin >> a[i];
            }
            sort(a.begin(), a.end());
            for (int i = 0; i < n-1; i++) {
                cout << a[(n -1 + n - i) * i / 2] << ' ';
            }
            cout << a.back() << "\n";
        }
    };
    return 0;
}