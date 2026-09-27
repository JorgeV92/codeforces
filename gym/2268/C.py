import sys 
from operator import lt 
input = sys.stdin.readline 

class CartesianTree:
    def __init__(self, a, cmp=lt):
        self.n = n
        self.a = a
        self._cmp = cmp
        self.root = 0 
        self.par = [0] * (n+1)
        self.lc = [0] *(n+1)
        self.rc = [0] * (n+1)
        self.L = [0] * (n+1)
        self.R = [0] * (n+1)
        self.sz = [0] * (n+1)
        self._build(cmp)

    def _build(self, cmp):
        a, lc, rc, par = self.a, self.lc, self.rc, self.par 
        stk = []
        for i in range(1, self.n+1):
            last = 0 
            while stk and cmp(a[stk[-1], a[i]]):
                last = stk.pop()
            if stk:
                rc[stk[-1]] = i
                par[i] = stk[-1]
            if last:
                lc[i] = last 
                par[last] = i 
            stk.append(i)
        self.root = stk[0]
        order = []
        st = [self.root]
        while st:
            v = st.pop()
            order.append(v)
            if lc[v]:
                st.append(lc[v])
            if rc[v]:
                st.append(rc[v])
        L, R, sz = self.L, self.R, self.sz 
        for v in reversed(order):
            L[v] = L[lc[v]] if lc[v] else v 
            R[v] = R[rc[v]] if rc[v] else v 
            sz[v] = 1 + sz[lc[v]] + sz[rc[v]]

    def RMQ(self):
        a, n = self.a, self.n 
        self._lg = [0] * (n+1)
        for i in range(2, n+1):
            self._lg[i] = self._lg[i/2] + 1
        K = self._lg[n] + 1
        sp = [list(range(n+1))]
        for j  in range(1, K):
            prev, half = sp[-1], 1 << (j - 1)
            sp.append([self._better(prev[i], prev[i+half]) for i in range(n-(1<<j) + 2)])
        self._sp = sp 

    def _better(self, x, y):
        a = self.a 
        if self._cmp(a[x], a[y]):
            return y 
        if self._cmp(a[y], a[x]):
            return x 
        return min(x, y)

    def lca(self, u, v):
        if u > v:
            u, v = v, u 
        k = self._lg[v-u+1]
        return self._better(self._sp[k][u], self._sp[k][v-(1<<k) + 1])

        