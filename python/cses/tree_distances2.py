import sys 
sys.setrecursionlimit(300000)
input = sys.stdin.readline

n = int(input())

g = [[] for _ in range(n)]

for _ in range(n-1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a].append(b)
    g[b].append(a)

dp = [0] * n
ans = [0] * n 

def dfs1(u: int=0, f: int=-1, depth: int=0):
    ans[0] += depth
    dp[u] = 1
    for v in g[u]:
        if v != f:
            dfs1(v, u, depth+1)
            dp[u] += dp[v]

def dfs2(u:int=0, f:int=-1):
    for v in g[u]:
        if v != f:
            ans[v] = ans[u] + n - 2 * dp[v]
            dfs2(v, u)

dfs1()
dfs2()

for a in ans:
    print(a, end=' ')
print()

