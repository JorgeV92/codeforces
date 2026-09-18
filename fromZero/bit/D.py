import sys 
input = sys.stdin.readline

class BinaryIndexTree:
    def __init__(self, _N):
        self.N = _N 
        self.data = [0] * self.N 
    def add(self, p, x):
        p += 1
        while p <= self.N:
            self.data[p-1] += x
            p += p & -p 
    def sum(self, r):
        s = 0
        while r:
            s += self.data[r-1]
            r -= r & -r 
        return s 


n, q = map(int, input().split())
a = list(map(int, input().split()))
b = BinaryIndexTree(n)
while q:
    l, r = map(int,input().split())
    l -= 1
    r -= 1
    b.add(l, 1)
    if r+1 < n:
        b.add(r+1,-1)
    q -= 1
f = [0] * n
for i in range(n):
    f[i] = b.sum(i+1)
a.sort()
f.sort()
ans = 0
for i in range(n):
    ans += a[i] * f[i]
print(ans)
