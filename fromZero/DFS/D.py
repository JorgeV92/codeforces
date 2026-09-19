import sys 
sys.setrecursionlimit(300000)
input = sys.stdin.readline 

N, M = map(int, input().split())
g = [[] for _ in range(N)]
for _ in range(M):
    u, v = map(int, input().split())
    u -= 1 
    v -= 1
    g[u].append(v)
    g[v].append(u)
vis = [False] * N 
ans = 0

def dfs(v):
    vis[v] = True 
    cycle = (len(g[v]) == 2)
    for u in g[v]:
        if not vis[u]:
            if not dfs(u): 
                cycle = False 
    return cycle

for i in range(N):
    if not vis[i]:
        if dfs(i): ans += 1 

print(ans)
        
