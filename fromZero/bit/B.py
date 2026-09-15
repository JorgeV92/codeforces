import sys 
from collections import defaultdict
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

n = int(input())
a = list(map(int,input().split()))
freq = defaultdict(int)
L = [0]*n
for i, x in enumerate(a):
    freq[x] += 1
    L[i] = freq[x]
bit = BinaryIndexTree(n+1)
freq.clear()
ans = 0
for i in range(n-1,-1,-1):
    freq[a[i]] += 1
    r = freq[a[i]]
    ans += bit.sum(L[i])
    bit.add(r, 1)
    
print(ans)