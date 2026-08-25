import sys
sys.setrecursionlimit(300000)
input = sys.stdin.readline

n, m = map(int, input().split())

odd = [0] * n
vis = [0] * n
timer = 1
ans = []

g = [[] for _ in range(n)]

for _ in range(m):
    a, b = map(int, input().split())
    a -= 1; b -= 1
    g[a].append(b)
    g[b].append(a)

def dfs(u: int, f: int):
    global timer
    vis[u] = timer 
    timer += 1
    for v in g[u]:
        if v != f:
            if not vis[v]:
                dfs(v, u)
                if odd[v]:
                    ans.append((v, u))
                    odd[v] = 0
                else:
                    ans.append((u, v))
                    odd[u] ^= 1
            elif vis[u] > vis[v]:
                ans.append((u, v))
                odd[u] ^= 1

for i in range(n):
    if vis[i] == 0:
        dfs(i, -1)

if any(odd[:]):
    print("IMPOSSIBLE")
else:
    for a,b in ans:
        print(a+1, b+1)


