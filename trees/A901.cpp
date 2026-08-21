#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int h; cin >> h;
    int n = 0; vector<int> a(h+1);
    for (int i = 0; i <= h; ++i) {
        cin>>a[i];
        n += a[i];
    }
    int bad = - 1;
    for (int i = 1; i <= h; ++i) {
        if (a[i-1] > 1 && a[i] > 1) {
            bad = i;
            break;
        }
    }
    if (bad == -1) {
        cout << "perfect\n";
        return 0;
    }
    cout << "ambiguous\n";

    vector<int> st(h+1);
    int cur = 1;
    for (int i = 0; i <= h; ++i) {
        st[i] = cur;
        cur += a[i];
    }
    vector<int> p1(n+1), p2(n+1);
    for (int i = 1; i <= h; i++) {
        for (int j = 0; j < a[i]; ++j) {
            int v = st[i] + j;
            p1[v] = p2[v] = st[i-1];
        }
    }
    p2[st[bad]] = st[bad-1] + 1;
    for (int i = 1; i <= n; i++) {
        cout << p1[i] << " \n"[i==n];
    }
    for (int i = 1; i <= n; ++i) {
        cout << p2[i] << " \n"[i==n];
    }
    return 0;
}
