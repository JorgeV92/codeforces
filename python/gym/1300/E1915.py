import sys
input = sys.stdin.readline
print = sys.stdout.write

def solve():
    n = int(input())
    a = list(map(int,input().split()))
    seen = {0}
    prefix = 0
    for i, x in enumerate(a):
        if i % 2 == 0:
            prefix += x
        else:
            prefix -= x
        if prefix in seen:
            print("YES\n")
            return
        seen.add(prefix)
    print("NO\n")

t = int(input())

for _ in range(t):
    solve()