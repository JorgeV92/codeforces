import sys
from collections import deque 
input = sys.stdin.readline

n = int(input())
g = [[]*(n-1) for _ in range(n)]
for _ in range(n-1):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    g[u].append(v)
    g[v].append(u)
a = list(map(int, input().split()))
a = [x-1 for x in a]
if a[0] != 0:
    print("No")
    sys.exit(0)
pos =[0] * n
for i in range(n): pos[a[i]] = i 
for v in range(n): g[v].sort(key=lambda i: pos[i])
q = deque([0])
vis = [False] * n
vis[0] = True; 
ans = []
while q:
    v = q.popleft()
    ans.append(v)
    for u in g[v]:
        if not vis[u]:
            vis[u] = True
            q.append(u)
if ans == a: print("Yes")
else: print("No")
