
MOD = 1e9+7

def main():
    n, m = map(int, input().split())
    g = [[] for _ in range(n)]
    rg = [[] for _ in range(n)]
    vis = [False] * n
    order = []
    
    def dfs1(u: int) -> None:
        vis[u] = True
        for v in g[u]:
            if not vis[v]:
                dfs1(v)
        order.append(u)

    mn_cost = float('inf')
    mn_cnt = 0

    def dfs2(u):
        nonlocal mn_cost
        nonlocal mn_cnt
        vis[u] = True 
        if cost[u] < mn_cost:
            mn_cost = cost[u]
            mn_cnt = 1 
        elif cost[u] == mn_cost:
            mn_cnt += 1 
        for v in rg[u]:
            dfs2(v)

    cost = list(map(int, input().split()))

    for i in range(m):
        u, v = map(int, input().split())
        u -= 1 
        v -= 1
        g[u].append(v)
        rg[v].append(u)

    for i in range(n):
        if not vis[i]:
            dfs1(i)

    reversed(order)
    vis = [False] * n

    total = 0
    ways = 1 
    for u in order:
        if not vis[u]:
            dfs2(u)
        total += mn_cost
        ways = (ways * mn_cnt) % MOD 
    print(f"{total} {ways}")


    
if __name__ == '__main__':
    main()
