#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

template<typename T, typename Cmp = std::less<T>> class CartesianTree {
public:
    int n=0, root = 0;
    std::vector<int> par, lc, rc;
    std::vector<int> L, R, sz;
    CartesianTree() = default;
    explicit CartesianTree(const std::vector<T>& a, int n_) { build(a, n_); }
    void build(const std::vector<T>& a, int n_) {
        n = n_;
        val = a;
        par.assign(n+1, 0);
        lc.assign(n+1, 0);
        rc.assign(n+1, 0);
        L.assign(n+1,0);
        R.assign(n+1,0);
        sz.assign(n+1, 0);
        Cmp cmp;
        std::vector<int> stk;
        stk.reserve(n);
        for (int i = 1; i <= n; ++i) {
            int last = 0;
            while (!stk.empty() && cmp(a[stk.back()], a[i])) {
                last = stk.back();
                stk.pop_back();
            }
            if (!stk.empty()) { rc[stk.back()] = i; par[i] = stk.back(); }
            if (last) { lc[i] = last; par[last] = i; }
            stk.push_back(i);
        }
        root = stk.front();
        std::vector<int> order;
        order.reserve(n);
        for (std::vector<int> st2 = {root}; !st2.empty(); ) {
            int v = st2.back(); st2.pop_back();
            order.push_back(v);
            if (lc[v]) st2.push_back(lc[v]);
            if (rc[v]) st2.push_back(rc[v]);
        }
        for (auto it = order.rbegin(); it != order.rend(); ++it) {
            int v = *it;
            L[v] = lc[v] ? L[lc[v]] : v;
            R[v] = rc[v] ? R[rc[v]] : v;
            sz[v] = 1 + sz[lc[v]] + sz[rc[v]]; 
        }
    }  
    void RMQ() {
        lg.assign(n+1, 0);
        for (int i = 2; i <= n; i++) lg[i] = lg[i/2] + 1;
        int K = lg[n] + 1;
        sp.assign(K, std::vector<int>(n+1));
        for (int i = 1; i <= n; i++) sp[0][i] = i;
        for (int j = 1; j < K; j++) 
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
                sp[j][i] = better(sp[j-1][i], sp[j-1][i + (1 << (j-1))]);
    }
    int lca(int u , int v) {
        if (u > v) std::swap(u, v);
        int k = lg[v-u+1];
        return better(sp[k][u], sp[k][v-(1<<k) + 1]);
    } 
    const T& value(int v) { return val[v]; }
private:
    std::vector<T> val;
    std::vector<int> lg;
    std::vector<std::vector<int>> sp;    
    int better(int x, int y) { 
        Cmp cmp;
        if (cmp(val[x], val[y])) return y;
        if (cmp(val[y], val[x])) return x;
        return std::min(x, y);
    }
};

const int B = 18;
const int MAXV = 1 << B;
int n, M;
bool found; 
std::vector<int> a, s, cntv;
CartesianTree<int> ct; // max

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T;  std::cin >> T;
    ct.assign(MAXV, 0);
    while (T--) {

        auto travers = [&]() {
            struct Frame = {int v, state; };
            std::vector<Frame> stk;
            stk.push_back(ct.root, 0);
            while (!stk.empty()) {
                int v = stk.back().v, state = stk.back().state;
                if (state == 0) {
                    if (v==0) { stk.pop_back(); continue; }
                    if (ct.L[v] == ct.R[v]) { cntv[s[v]]++; stk.pop_back(); continue;}
                    stk.back().state = 1;
                    int leftSize= v - ct.L[v], rigtSize = ct.R[v] - v;
                    if (rigtSize > leftSize) stk.push_back({ct.lc[v], 0});
                    else stk.push_back({ct.rc[v], 0});
                    continue;
                }
                int l = ct.L[v], r = ct.R[v];
                int leftSize = v - l, rightSize= r - v;
                if (state == 1) {
                    stk.back().state = 2;
                    if (rightSize > leftSize) {
                        for (int i = l; i < v; i++) cntv[s[i]]--;
                        stk.push_back({ct.rc[v], 0});
                    } else {
                        for (int i = v+1; i <= r; i++) cntv[s[i]]--;
                        stk.push_back({ct.lc[v], 0});
                    }
                    continue;
                }
                bool okV = ((a[v] & M) == M);
                if (rightSize > leftSize) {
                }
            }
        };

        std::cin >> n;
        a.assign(n+1,0);
        s.assign(n+1, 0);
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        ct.build(a, n);

    }
    return 0;
}