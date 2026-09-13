import sys 
input = sys.stdin.readline 

def solve():
    s = input().strip()
    m = int(input())
    l = input().strip()
    r = input().strip()
    p = 0
    for i in range(m):
        q = p
        for d in range(int(l[i]), int(r[i]) + 1):
            pos = s.find(str(d), p)
            if pos == -1: 
                print("YES") 
                return 
            q = max(q, pos+1)
    print("NO")

t = int(input())
for _ in range(t):
    solve()