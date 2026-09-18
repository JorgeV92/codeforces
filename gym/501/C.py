import sys 
from collections import deque
input = sys.stdin.readline 

n = int(input())
deg = [0] * n 
xr = [0] * n 
for i in range(n): deg[i], xr[i] = map(int, input().split())
q = deque()
for i in range(n): 
    if deg[i] == 1: 
        q.append(i) 
edges = []
while q:
    v = q.popleft()
    if deg[v] != 1: continue
    u = xr[v]
    edges.append((v,u))
    deg[v] -= 1
    deg[u] -= 1
    xr[u] ^= v
    if deg[u] == 1: q.append(u)
print(len(edges))
for u, v in edges:
    print(u, v)


