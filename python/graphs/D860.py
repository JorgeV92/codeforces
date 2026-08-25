import sys
sys.setrecursionlimit(300000)
input = sys.stdin.readline

n, m = map(int, input().split())

g = [[] for _ in range(n)]
vis = [False] * n
ans = []

for _ in range(m):
    a, b = map(int, input().split())
    a -= 1; b -= 1
    g[a].append(b)
    g[b].append(a)

# true if not used edge, false used edge
def dfs(u:int, f:int) -> bool: 
    vis[u] = True
    curr = []
    for v in g[u]:
        if v != f:
            if vis[v]:
                if u < v:
                    curr.append(v)
            else:
                if dfs(v, u):
                    curr.append(v)

    for i in range(0, len(curr)-1, 2):
        ans.append((curr[i], u, curr[i+1]))

    if len(curr) % 2 == 0:
        return True 

    if f != -1:
        ans.append((curr[-1], u, f))
    return False 

for i in range(n):
    if not vis[i]:
        dfs(i, -1)

print(len(ans))

for a, b, c in ans:
    print(a+1, b+1, c+1)