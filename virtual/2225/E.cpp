#include <iostream>
#include <vector>
#include <random>
#include <cstdint>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <chrono>
#include <cmath>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int64_t floordiv(int64_t a, int64_t b) {
    if (a >= 0) return a / b;
    return -((-a + b - 1) / b);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, r; cin>>n>>r;
    vector<pair<int,int>> p(n);
    for (auto& [x, y] : p) cin>>x>>y;
    int need = (89*n+99)/100;
    int h =(int)ceil(sqrt((long double)3)*r);
    int64_t dom = 2LL*r*h;
    int64_t rr = 1LL*r*r;
    auto eval = [&](int ox, int oy, vector<pair<int,int>>* out=nullptr) -> int {
        int got = 0;
        if (out) out->clear();
        for (auto [x, y] : p) {
            int64_t row = floordiv((int64_t)y-oy,h);
            bool ok = false;
            pair<int,int> ctr;
            for (int64_t b = row; b <= row + 1 && !ok; b++) {
                int64_t  cy = oy + b * 1LL * h;
                int64_t dy = (int64_t)y - cy;
                if (dy * dy > rr) continue;
                int64_t shift = ox + ((b&1) ? r : 0);
                int64_t a = floordiv((int64_t)x - shift, 2LL*r);

                for (int64_t s = a; s <= a+1 && !ok; ++s) {
                    int64_t cx = shift + s * 2LL * r;
                    int64_t dx = (int64_t)x - cx;

                    if (dx * dx + dy * dy <= rr) {
                        ok = true;
                        ctr = {(int)cx, (int)cy};
                    }
                }
            }
            if (ok) {
                ++got;
                if (out)out->push_back(ctr);
            }
        }
        return got;
    };
    int bestc = -1;
    int bestx = 0;
    int besty = 0;

    if (dom * n <= 20000000LL) {
        for (int oy = 0; oy < h && bestc < need; ++oy) {
            for (int ox = 0; ox < 2 * r && bestc < need; ox++) {
                int cur = eval(ox, oy);
                if (cur > bestc) {
                    bestc = cur;
                    bestx = ox;
                    besty = oy;
                }
            }
        }
    } else {
        vector<pair<int,int>> cand = {
            {0,0},
            {r % (2*r), 0},
            {0, h/2},
            {r % (2*r), h/2},
        };

        for (auto [ox, oy] : cand) {
            int cur = eval(ox, oy);
            if (cur > bestc) {
                bestc = cur;
                bestx = ox;
                besty = oy;
            }
        }

        uniform_int_distribution<int> DX(0, 2*r-1);
        uniform_int_distribution<int> DY(0, h-1);

        for (int it = 0; it < 5000 && bestc < need; it++) {
            int ox = DX(rng);
            int oy = DY(rng);
            int cur = eval(ox, oy);
            if (cur > bestc) {
                bestc = cur;
                bestx = ox;
                besty = oy;
            }
        }
    }
    vector<pair<int,int>> ans;
    eval(bestx, besty, &ans);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout<<ans.size()<<"\n";
    for (auto [x, y] : ans) {
        cout<<x<<' '<<y<<'\n';
    }

    return 0;
}