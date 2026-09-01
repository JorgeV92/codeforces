import sys 
input = sys.stdin.readline


def solve():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int,input().split()))
    # dp = [[False] * (1<<9) for _ in range(n+1)]
    # dp[0][0] = True
    # for i in range(n):
    #     for mask in range(1<<9):
    #         if not dp[i][mask]: continue
    #         for k in range(m):
    #             nm = mask | (a[i]&b[k])
    #             dp[i+1][nm] = True 
    # x = 0
    # while not dp[n][x]:
    #     x += 1
    # print(x)


    for x in range(1<<9):
        good = True 
        for aa in a:
            found = False 
            for bb in b:
                c = aa & bb 
                if (c | x) == x:
                    found = True 
                    break 
            if not found:
                good = False 
                break 
        if good:
            print(x)
            return 

solve()
