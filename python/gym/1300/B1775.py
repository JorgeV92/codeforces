import sys
input = sys.stdin.readline

def solve():
    n = int(input())
    arrs = []
    cnt = {}
    for _ in range(n):
        r = list(map(int,input().split()))
        k = r[0]
        bits = r[1:]
        arrs.append(bits)
        for b in bits:
            cnt[b] = cnt.get(b, 0) + 1
    for bits in arrs:
        if all(cnt[b] > 1 for b in bits):
            print("Yes")
            return 
    print("No")


t = int(input())

for _ in range(t):
    solve()