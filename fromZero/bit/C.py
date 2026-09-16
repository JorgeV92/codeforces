import sys 
input = sys.stdin.readline

class BinaryIndexTree:
    def __init__(self, _N):
        self.N = _N 
        self.data = [0] * self.N 
    def add(self, p, x):
        p += 1
        while p <=  self.N:
            self.data[p-1] += x
            p += p & -p 
    def sum(self, r):
        s = 0
        while r:
            s += self.data[r-1]
            r -= r & -r 
        return s 
    def summ(self, l, r):
        return self.sum(r) - self.sum(l)
    def range_sum(self, l, r, x):
        self.add(l, x)
        if r +1 < self.N: self.add(r+1,-x)


n, m, k = map(int, input().split())
a = list(map(int, input().split()))
ops = []

ops_bit = BinaryIndexTree(m)
for _ in range(m):
    b = list(map(int, input().split()))
    b[0] -= 1
    b[1] -= 1
    ops.append(b)

for _ in range(k):
    x, y = map(int,input().split())
    x -= 1; y -= 1
    ops_bit.range_sum(x, y, 1)

arr_bit = BinaryIndexTree(n)
for i in range(m):
    t = ops_bit.sum(i+1)
    arr_bit.range_sum(ops[i][0], ops[i][1], ops[i][2] * t)
for i in range(n):
    a[i] += arr_bit.sum(i+1)
    print(a[i], end=' ')
print()


