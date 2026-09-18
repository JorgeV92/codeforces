import sys 
import heapq
input = sys.stdin.readline

n, m = map(int,input().split())
g = [[] * m for _ in range(n)]
for _ in range(m):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    g[u].append(v)
    g[v].append(u)
vis = [False] * n
h = []
heapq.heappush(h, 0)
ans = []
while h:
    v = heapq.heappop(h)
    if vis[v]: continue
    ans.append(v)
    vis[v] = True 
    for u in g[v]:
        if not vis[u]:
            heapq.heappush(h, u)
ans = [x + 1 for x in ans]
print(*ans)
