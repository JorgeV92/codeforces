import sys 
from collections import deque
input = sys.stdin.readline 

n, m = map(int, input().split())
q = deque([n])
vis = set()
vis.add(n)
opt = 0
mx = 2 * max(n,m)
while q:
    sz = len(q)
    for _ in range(sz):
        v = q.popleft()
        if v == m: 
            print(opt)
            sys.exit(0)
        u = v*2
        w = v - 1
        if u not in vis and u <= mx: 
            q.append(u) 
            vis.add(u)
        if w not in vis and w > 0: 
            q.append(w)
            vis.add(w)
    opt += 1
print(-1)
