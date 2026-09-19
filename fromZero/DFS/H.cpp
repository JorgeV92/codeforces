#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

template<typename T, int SZ> struct LazySeg {
    static_assert((SZ & (SZ-1)) == 0);
    static constexpr T INF = 1e9;
    const T ID{}; T cmb(T a, T b) { return std::min(a, b); }
    T seg[2*SZ], lazy[2*SZ];
    LazySeg() { for (int i = 0; i < 2*SZ; i++) seg[i] = INF, lazy[i] = ID; }
    void push(int ind, int L, int R) {
        seg[ind] += lazy[ind];
        if (L != R) for (int i = 0; i < 2; ++i) lazy[2*ind+i] += lazy[ind];
        lazy[ind] = 0;
    }
    void pull(int ind) { seg[ind]=cmb(seg[2*ind], seg[2*ind+1]); }
    void build() { for (int i = SZ-1; i >= 1; i--) pull(i); }
    void upd(int lo, int hi, T inc, int ind=1, int L=0, int R=SZ-1) {
        push(ind,L,R); if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] += inc; push(ind,L,R); return;
        }
        int M = (L+R)/2; upd(lo,hi,inc,2*ind,L,M);
        upd(lo,hi,inc,2*ind+1,M+1,R); pull(ind);
    }
    T query(int ind=1, int L=0, int R=SZ-1) {
        push(ind,L,R); if (L == R) return L;
        int M = (L+R)/ 2; push(2*ind,L,M); push(2*ind+1,M+1,R);
        if (seg[2*ind+1] ==0) return query(2*ind+1,M+1,R);
        return query(2*ind,L,M);
    } 
};

const int SZ = 1<<18;

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
        while (T--) {
        int n, m; std::cin >> n >> m;
        std::vector<std::vector<int>> rmv(n);
        LazySeg<int,SZ> st;
        for (int v = 0; v < n; ++v) {
            st.seg[SZ+v] = v;
        }
        for (int i = 0; i < m; ++i) {
            int u, v; std::cin >> u >> v;
            u--; v--;
            rmv[u].push_back(v);
            st.seg[SZ+v]--;
        }
        st.build();
        std::vector<int> ans;
        for (int i = 0; i < n; i++) {
            int u = st.query();
            ans.push_back(u);
            st.upd(u,u,LazySeg<int,SZ>::INF);
            if (u+1 < n) st.upd(u+1,n-1,-1);
            for (int v : rmv[u]) st.upd(v,v,+1);
        }
        for (int i = 0; i < n; ++i) {
            std::cout << ans[i] + 1 << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}   