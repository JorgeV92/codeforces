import sys
input = sys.stdin.readline 
sys.setrecursionlimit(1000000)

n, m = map(int, input().split())

tin = [0]*(n+1) 
low = [0]*(n+1)
g = [[] for _ in range(n+1)]
scc = 0
timer = 0
stack = []
two_edge_components = [[] for _ in range(n+1)]

for i in range(m):
    u, v = map(int, input().split())
    g[u].append(v)
    g[v].append(u)

def dfs(v, f): 
    global timer, scc 
    timer += 1
    tin[v] = timer
    low[v] = timer
    stack.append(v)
    mult_edges = False 
    for to in g[v]:
        if to == f and not mult_edges:
            mult_edges = True 
            continue
        if not tin[to]:
            dfs(to, v)
            low[v] = min(low[v], low[to])
        else:
            low[v] = min(low[v], tin[to])
    if low[v] == tin[v]:
        while stack[-1] != v:
            two_edge_components[scc].append(stack.pop())
        two_edge_components[scc].append(stack.pop())
        scc += 1

for i in range(n):
    if not tin[i]: dfs(i, -1)

print(scc)
for c in range(scc):
    print(len(two_edge_components[c]), end=' ')
    for v in two_edge_components[c]:
        print(v, end=' ')
    print()