import sys
input = sys.stdin.readline

INF = 10**9

class LazySeg:
    def __init__(self, a):
        n = len(a)
        SZ = 1 << (n - 1).bit_length()
        self.n = n
        self.SZ = SZ
        self.seg = [INF] * (2 * SZ)
        self.lazy = [0] * (2 * SZ)
        for i, x in enumerate(a):
            self.seg[SZ + i] = x
        for i in range(SZ - 1, 0, -1):
            self.seg[i] = min(self.seg[2 * i], self.seg[2 * i + 1])

    def push(self, ind):
        x = self.lazy[ind]
        if x:
            left = 2 * ind
            right = left + 1

            self.seg[left] += x
            self.seg[right] += x

            self.lazy[left] += x
            self.lazy[right] += x

            self.lazy[ind] = 0

    def upd(self, lo, hi, inc, ind=1, L=0, R=None):
        if R is None:
            R = self.SZ - 1
        if lo <= L and R <= hi:
            self.seg[ind] += inc
            self.lazy[ind] += inc
            return
        self.push(ind)
        M = (L + R) // 2
        left = 2 * ind
        if lo <= M:
            self.upd(lo, hi, inc, left, L, M)
        if hi > M:
            self.upd(lo, hi, inc, left + 1, M + 1, R)
        self.seg[ind] = min(self.seg[left], self.seg[left + 1])

    def query(self):
        ind = 1
        L = 0
        R = self.SZ - 1

        while L != R:
            self.push(ind)

            M = (L + R) // 2
            right = 2 * ind + 1
            if self.seg[right] == 0:
                ind = right
                L = M + 1
            else:
                ind = 2 * ind
                R = M
        return L


T = int(input())

for _ in range(T):
    n, m = map(int, input().split())
    rmv = [[] for _ in range(n)]
    indeg = list(range(n))

    for _ in range(m):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        rmv[u].append(v)
        indeg[v] -= 1

    st = LazySeg(indeg)

    ans = []

    for _ in range(n):
        u = st.query()
        ans.append(u + 1)
        # Mark u 
        st.upd(u, u, INF)
        # Remove existing outgoing edges:
        # u -> u+1, ..., n-1
        if u + 1 < n:
            st.upd(u + 1, n - 1, -1)
        # Undo -1 for edges that don't actually exist
        for v in rmv[u]:
            st.upd(v, v, 1)

    print(*ans)