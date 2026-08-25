import sys
input = sys.stdin.readline

def solve():
    n, c, q = map(int, input().split())
    s = input().strip()
    op = []
    lenn = n 
    while c:
        l, r = map(int, input().split())
        op.append((lenn, l , r))
        lenn += r - l + 1
        c -= 1
        
    while q:
        k = int(input())
        for old, l, r in reversed(op):
            if k > old:
                k = l + (k - old) - 1
        print(s[k-1])
        q -= 1
        

t = int(input())

for _ in range(t):
    solve()