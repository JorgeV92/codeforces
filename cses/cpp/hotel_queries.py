import sys 
def solve():
    input = sys.stdin.buffer.readline
    n, m = map(int, input().split())
    h = list(map(int, input().split()))
    g = list(map(int, input().split()))
    size = 1 
    while size < n: size <<= 1
    seg = [0] * (4*n)
    for i in range(n): seg[i+size] = h[i]
    for i in range(size-1,0,-1): seg[i] = max(seg[i<<1], seg[i<<1|1])
    ans = []
    for x in g:
        if seg[1] < x:
            ans.append(0)
            continue
        node = 1 
        while node < size:
            if seg[node<<1] >= x: node = node<<1 
            else: node = node<<1|1 
        hh = node-size
        ans.append(hh+1)
        seg[node] -= x
        node //= 2
        while node:
            seg[node] = max(seg[node<<1], seg[node<<1|1])
            node //= 2
    print(*ans)

if __name__ == "__main__":
    solve()

