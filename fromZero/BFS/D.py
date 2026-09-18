import sys 
from collections import deque
input = sys.stdin.readline

n = int(input())
g = [[] for _ in range(n)]
for i in range(1,n):
    p = int(input()) - 1
    g[p].append(i)
q = deque([0])
while q:
    v = q.popleft()
    if not g[v]: continue
    leafs = 0
    for u in g[v]:
        if not g[u]:
            leafs += 1
        else:
            q.append(u)
    if leafs < 3:
        print("No")
        sys.exit(0)
print("Yes")