import sys
input = sys.stdin.readline

def solve():
    n , q= map(int, input().split())
    a = list(map(int, input().split()))
    cnt = sum(x.bit_count() % 2 == 0 for x in a)
    print(cnt, end=' ')
    for _ in range(q):
        p, x = map(int, input().split())
        p -= 1
        cnt -= (a[p].bit_count() % 2 == 0) 
        a[p] = x 
        cnt += (x.bit_count() % 2 == 0)
        print(cnt, end=' ')
    print()
    

T = int(input())
for _ in range(T):
    solve()