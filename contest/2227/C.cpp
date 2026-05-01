#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> a(N); for (int i = 0; i < N; i++) { cin >> a[i]; }
        vector<int> both, twos, neu, threes; 
        for (int i = 0; i < N; i++) {
            if (a[i] % 6 == 0) {
                both.push_back(a[i]);
            } else if (a[i] % 2 == 0) { 
                twos.push_back(a[i]);
            } else if (a[i] % 3 == 0) {
                threes.push_back(a[i]);
            } else {
                neu.push_back(a[i]);
            }
        }
        vector<int> all = both;
        all.reserve(both.size() + twos.size() + neu.size() + threes.size());
        all.insert(all.end(), twos.begin(), twos.end());
        all.insert(all.end(), neu.begin(), neu.end());
        all.insert(all.end(), threes.begin(), threes.end());
        for (int x : all) {
            cout << x << " ";
        }
        cout << '\n';
    }
    return 0;
}