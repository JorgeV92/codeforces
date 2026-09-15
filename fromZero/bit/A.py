import sys 
input = sys.stdin.readline

class BinaryIndexTree:
    def __init__(self, _N):
        self.N = _N
        self.data = [0] * self.N 
    def add(self, p: int, x: int):
        p += 1
        while p <= self.N:
            self.data[p-1] += x
            p += p & -p 
    def sum(self, r: int):
        s = 0
        while r:
            s += self.data[r-1]
            r -= r & -r 
        return s 
    def summ(self, l: int, r: int):
        return self.sum(r) - self.sum(l)


n, m = map(int, input().split())
bit = [BinaryIndexTree(n) for _ in range(m)] 
a = list(map(int,input().split()))
for i, x in enumerate(a):
    bit[x%m].add(i, x)

q = int(input())
for _ in range(q):
    line = input().split()
    t = line[0]
    if t == '+':
        p, x = map(int, line[1:])
        p -= 1
        bit[a[p]%m].add(p,-a[p])
        a[p] += x
        bit[a[p]%m].add(p, a[p])
        print(a[p])
    elif t == '-':
        p, x = map(int,line[1:])
        p -= 1
        if a[p] >= x:
            bit[a[p]%m].add(p, -a[p])
            a[p] -= x
            bit[a[p]%m].add(p, a[p])
        print(a[p])
    else:
        l, r, mod = map(int, line[1:])
        print(bit[mod].summ(l-1,r))


        