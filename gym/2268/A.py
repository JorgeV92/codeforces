import sys 
input = sys.stdin.readline

def solve():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    r = n - k + 1
    t = min(k-1, r)
    ans = 0
    for i in range(t):
        ans += max(a[i], a[n-i-1])
    if r > k-1:
        for j in range(k-1, n-k+1):
            ans += a[j]
    print(ans)

T = int(input())

for _ in range(T):
    solve()