import sys 
from collections import defaultdict
input = sys.stdin.readline

N = int(input())
g = defaultdict(list)
for _ in range(N):
    u, v = map(int, input().split())
    g[u].append(v)
    g[v].append(u)
s = -1 
for u, ne in g.items():
    if len(ne) == 1:
        s = u
        break 
prev = -1
cur = s 
while True:
    print(cur, end=' ')
    nxt = -1
    for u in g[cur]:
        if u != prev:
            nxt = u
            break
    if nxt == -1:
        break
    prev = cur
    cur = nxt 
print()