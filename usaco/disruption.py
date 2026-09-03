import sys 
import heapq
from collections import Counter
input = sys.stdin.readline 

class LCA:
    def __init__(self, _N):
        self.N = _N 
        d = 1 
        while (1<<d) < self.N: d += 1
        self.par = [[0]* self.N for _ in range(d)]
        self.adj = [[] for _ in range(self.N)]
        self.depth = [0] * self.N

    def ae(self, x, y):
        self.adj[x].append(y)
        self.adj[y].append(x)

    def gen(self, R=0):
        self.par[0][R] = R 
        self.dfs(R)

    def dfs(self, x=0):
        for i in range(1, len(self.par)):
            self.par[i][x] = self.par[i-1][self.par[i-1][x]]
        for y in self.adj[x]:
            if y != self.par[0][x]:
                self.par[0][y] = x
                self.depth[y] = self.depth[x]+1 
                self.dfs(y)

    def jmp(self, x, d):
        for i in range(len(self.par)):
            if (d>>i)&1: x = self.par[i][x]
        return x 

    def lca(self, x, y):
        if self.depth[x] < self.depth[y]: x, y = y, x 
        x = self.jmp(x, self.depth[x]-self.depth[y]) 
        if x == y: return x 
        for i in range(len(self.par)-1, -1,-1):
            X, Y = self.par[i][x], self.par[i][y]
            if X != Y:
                x = X; y = Y 
        return self.par[0][x]

    def dist(self, x, y):
        return self.depth[x] + self.depth[y] - 2 * self.depth[self.lca(x,y)]


class Bag:
    def __init__(self):
        self.cnt = Counter()
        self.heap = []
        self.size = 0

    def add(self, x, amount=1):
        self.cnt[x] += amount
        self.size += amount
        for _ in range(amount):
            heapq.heappush(self.heap, x)

    def remove(self, x):
        self.cnt[x] -= 1
        self.size -= 1

    def min_value(self):
        while self.heap and self.cnt[self.heap[0]] == 0:
            heapq.heappop(self.heap)
        return self.heap[0] if self.heap else None 

    def merge(self, other):
        if self.size < other.size:
            self.cnt, other.cnt = other.cnt, self.cnt 
            self.heap, other.heap = other.heap, self.heap
            self.size, other.size = other.size, self.size 

        for x, count in other.cnt.items():
            if count > 0:
                self.cnt[x] += count 
                self.size += count 
                for _ in range(count):
                    heapq.heappush(self.heap, x)


def solve():
    n, m = map(int, input().split())
    lca = LCA(n)
    edges = []
    for _ in range(n-1):
        a, b = map(int, input().split())
        a -= 1; b -= 1
        lca.ae(a, b)
        edges.append((a,b))
    add = [[] for _ in range(n)]
    rem = [[] for _ in range(n)]
    lca.gen()
    for _ in range(m):
        p, q, r = map(int,input().split())
        p -= 1; q -= 1
        L = lca.lca(p,q)
        add[p].append(r)
        add[q].append(r)
        rem[L].append(r)
    ans = [-1] * n

    def dfs(x, p):
        bag = Bag()
        for y in lca.adj[x]:
            if y != p:
                child_bag = dfs(y, x)
                if child_bag.size > bag.size:
                    bag, child_bag, = child_bag, bag
                bag.merge(child_bag)
        for y in add[x]: bag.add(y)
        for y in rem[x]: 
            bag.remove(y); bag.remove(y)
        mn = bag.min_value()
        if mn is not None:
            ans[x] = mn 
        return bag 

    dfs(0,-1)
    out = []
    for a, b in edges:
        if lca.depth[a] < lca.depth[b]: a, b = b, a
        out.append(str(ans[a]))

    print("\n".join(out))

solve()