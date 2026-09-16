#include <iostream>
#include <vector>

using i64 = long long; 

template<typename T> struct BIT {
    int N; std::vector<T> data; 
    void init(int _N) { N = _N; data.resize(N); }
    void add(int p, T x) { for (++p; p<=N; p+=p&-p) data[p-1]+=x; }
    T sum(int r) {T s=0; for(;r; r-=r&-r) s+=data[r-1]; return s; }   
    T sum(int l, int r) { return sum(r) - sum(l); }
    void range_add(int l, int r, T x) { add(l, x); if (r+1<N) add(r+1,-x); }
};

struct opt { int l, r; i64 d; };

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int n, m, k; std::cin >> n >> m >> k;
    std::vector<i64> a(n); for (auto& x : a) std::cin >> x;
    std::vector<opt> ops(m);
    for (auto& [l, r, d] : ops) {
        std::cin >> l >> r >> d;
        --l; --r;
    }
    BIT<i64> opBit;
    opBit.init(m);
    while (k--) {
        int x, y; std::cin >> x >> y;
        --x; --y;
        opBit.range_add(x, y, 1);
    }
    BIT<i64> arrBit; arrBit.init(n);
    for (int i = 0; i < m; ++i) {
        i64 t = opBit.sum(i+1);
        arrBit.range_add(ops[i].l, ops[i].r, t * ops[i].d);
    }
    for (int i = 0; i < n; ++i) {
        a[i] += arrBit.sum(i+1); 
        std::cout << a[i] << ' ';
    } 
    std::cout << '\n';
    return 0;
}