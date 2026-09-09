import sys 
input = sys.stdin.readline

def solve():
    n = int(input())
    a = list(map(int, input().strip())) 
    a = [x - 1 for x in a]
    pref = [0] * (n+1)
    for i in range(n):
        pref[i+1] = pref[i] + a[i]
    mp = {}
    ans = 0
    for i in range(n+1):
        ans += mp.get(pref[i], 0) 
        mp[pref[i]] = mp.get(pref[i], 0) + 1
    print(ans)

t = int(input())
while t:
    solve()
    t -= 1



