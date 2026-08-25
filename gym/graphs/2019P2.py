n, m = map(int, input().split())
g = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a].append(b)
    g[b].append(a)

color = [0]*n

for p in range(n):
    used = set()
    for v in g[p]:
        if color[v] != 0:
            used.add(color[v])
    for c in range(1,5):
        if c not in used:
            color[p] = c
            break
print("".join(map(str, color)))