import sys
input = sys.stdin.readline

class DSU:
    def __init__(self, n):
        self.e = [-1]*n

    def get(self, x):
        if self.e[x] < 0: return x
        self.e[x] = self.get(self.e[x])
        return self.e[x]

    def same_set(self, x, y):
        return self.get(x) == self.get(y)

    def unite(self, x, y):
        x, y = self.get(x), self.get(y)
        if x == y: return False 
        if self.e[x] > self.e[y]: x, y = y, x
        self.e[x] += self.e[y]; self.e[y] = x 
        return True


N, M, K = map(int, input().split())
edges = []
for i in range(M):
    u, v, w = map(int,input().split())
    u -= 1; v -= 1
    edges.append((u,v,w,i))
dsu = [DSU(N) for _ in range(K)] 
edges.sort(key=lambda x: x[2], reverse=True)
ans = [0]*M

for i in range(M):
    e = edges[i]
    lo = 1 
    hi = K+1
    while lo < hi:
        mid = (lo+hi) >> 1
        if mid <= K and dsu[mid-1].same_set(e[0], e[1]):
            lo = mid +1 
        else: hi = mid 
    if lo <= K:
        dsu[lo-1].unite(e[0], e[1])
        ans[e[3]] = lo 
    else: ans[e[3]] = 0
for x in ans:
    print(x) 
