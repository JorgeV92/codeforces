#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin>> n;
    vector<int> a(n); for (int& x : a) cin>>x;
    int i = 0;
    int64_t ans = 0;
    sort(a.begin(), a.end());
    while (i < n) {
        ans += n-i;
        while (i+1 < n && a[i] == a[i+1]) i++;
        i++;
    }
    cout << ans<<'\n';
    return 0;
}

