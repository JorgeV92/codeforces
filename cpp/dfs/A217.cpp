#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define vi vector<int>

struct dsu {
    int N; vi e; void init(int n) { N = n; e = vi(N,-1); }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool sameSet(int x, int y) { return get(x) == get(y); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) {
        x = get(x); y = get(y); if (x == y) return false;
        if (e[x] < e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x; N--;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    auto jorgee = [&]() -> void {
        int n; cin >> n;
        vector<pair<int,int>> coor(n); 
        for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            x--; y--;
            coor[i] = make_pair(x, y);
        }
        dsu D;
        D.init(n);
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                auto& [x1, y1] = coor[i];
                auto& [x2, y2] = coor[j];
                if (x1 == x2 || y1 == y2) {
                    D.unite(i, j);
                }
            }
        }
        cout << (D.N -1)  << "\n";
    }; jorgee();
    return 0;
}