def solve():
    n = int(input())
    a = list(map(int, input().split()))
    diff = [n]* n
    for i in range(n-2,-1,-1):
        if a[i] != a[i+1]:
            diff[i] = i+1
        else:
            diff[i] = diff[i+1]
    q = int(input())

    while q:
        l, r = map(int,input().split())
        l -= 1; r -= 1
        j = diff[l]
        if j <= r:
            print(l+1, j+1)
        else:
            print(-1,-1)
        q -= 1


t = int(input())

for _ in range(t):
    solve()