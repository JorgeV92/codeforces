import sys 
input = sys.stdin.readline

SZ = 1<<18

class LazySeg:
    def __init__(self):
        assert((SZ & (SZ-1)) == 0) 
        self.SZ = SZ 
        INF = 10**9
        self.seg = [INF] * (2*self.SZ)
        self.lazy = [0] * (2*self.SZ)

    def cmb(self, a, b):
        return min(a, b)

    def push(self, ind, L, R):
        self.seg[ind] += self.lazy[ind]
        if (L != R): 
            for i in range(2): 
                self.lazy[2*ind+i] += self.lazy[ind]
        self.lazy[ind] = 0 

    def pull(self, ind):
        self.seg[ind] = self.cmb(self.seg[2*ind], self.seg[2*ind+1]) 

    def build(self):
        for i in range(self.SZ-1,0,-1):
            self.pull(i)

    def upd(self, lo, hi, inc, ind=1, L=0, R=SZ-1):
        self.push(ind,L,R)
        if hi < L or R < lo: return
        if lo <= L and R <= hi: 
            self.lazy[ind] += inc
            self.push(ind,L,R) 
            return
        M = (L+R) // 2 
        self.upd(lo,hi,inc,2*ind,L,M) 
        self.upd(lo,hi,inc,2*ind+1,M+1,R)
        self.pull(ind)

    def query(self, ind=1, L=0, R=SZ-1):
        self.push(ind,L,R)
        if L == R: return L 
        M = (L+R) // 2 
        self.push(2*ind,L,M) 
        self.push(2*ind+1,M+1,R)
        if self.seg[2*ind+1] == 0:
            return self.query(2*ind+1,M+1, R)
        return self.query(2*ind,L,M)

T = int(input())

for _ in range(T):
    n, m = map(int, input().split())
    rmv = [[] for _ in range(n)]
    st = LazySeg()
    for v in range(n):
        st.seg[SZ+v] = v 
    for i in range(m):
        u, v = map(int, input().split())
        u -= 1 
        v -= 1
        rmv[u].append(v)
        st.seg[SZ+v] -= 1
    st.build()
    ans = []
    for i in range(n):
        u = st.query()
        ans.append(u)
        st.upd(u, u, 10**9)
        if u + 1 < n: st.upd(u+1, n-1, -1)
        for v in rmv[u]: st.upd(v, v, 1)
    for i in range(n):
        print(ans[i]+1, end=' ')
    print()
        
        
        