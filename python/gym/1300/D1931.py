from collections import defaultdict

t = int(input())

for _ in range(t):
    n, x, y = map(int, input().split())
    a = list(map(int,input().split()))
    cnt = defaultdict(int)
    ans = 0
    for v in a:
        rx = v % x
        ry = v % y 
        need_x = (x - rx) % x
        need_y = ry
        ans += cnt[(need_x, need_y)]
        cnt[(rx,ry)] += 1 
    print(ans)