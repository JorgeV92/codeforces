import sys 
from collections import deque
input = sys.stdin.readline


T = int(input())
for _ in range(T):
    n = int(input())
    a = list(map(int, input().split()))
    a = [x-1 for x in a]
    g = [[] for _ in range(n)]
    for i in range(n):
        j = a[i]
        if a[j] == i and i > j: continue
        g[i].append(j)
        g[j].append(i)
    comp = 0
    cycles =0 
    vis = [False] * n 
    for i in range(n):
        if not vis[i]:
            vis[i] = True 
            q = deque([i])
            is_cycle= True 
            comp += 1
            while q:
                v = q.popleft()
                if len(g[v]) != 2: 
                    is_cycle = False 
                for u in g[v]:
                    if not vis[u]:
                        vis[u] = True 
                        q.append(u)
            if is_cycle:
                cycles += 1
    mx = comp
    mn = cycles
    if comp > cycles: mn += 1
    print(mn, mx)  
