from math import gcd

T = int(input())

while T:
    n = int(input())
    a = list(map(int,input().split()))

    cnt = [0] * 30
    for x in a:
        for bit in range(30):
            if (x >> bit) & 1:
                cnt[bit] += 1
    
    g = 0
    for c in cnt:
        g = gcd(g, c)

    if g == 0:
        print(*range(1, n+1))
        T -= 1
        continue

    ans = []
    for k in range(1,n+1):
        if g % k == 0:
            ans.append(k)
    print(*ans)

    T -= 1
