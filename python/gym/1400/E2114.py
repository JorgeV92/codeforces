import sys
sys.setrecursionlimit(300000)
input = sys.stdin.readline

def solve():
    n = int(input())
    A = list(map(int,input().split()))
    g =[[] for _ in range(n)]
    for _ in range(n-1):
        a, b = map(int,input().split())
        a -= 1; b -= 1 
        g[a].append(b)
        g[b].append(a)

    dp1 = [0] * n
    dp2 = [0] * n

    def dfs(u: int, f: int) -> None:
        nonlocal a
        for v in g[u]:
            if v == f:
                continue
            dp1[v] = max(A[v], A[v]-dp2[u]) 
            dp2[v] = min(A[v], A[v]-dp1[u])
            dfs(v, u)

    dp1[0] = dp2[0] = A[0]
    dfs(0,-1)
    print(*dp1)

t = int(input())

for _ in range(t):
    solve()
