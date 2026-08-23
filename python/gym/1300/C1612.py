t = int(input())

while t:
    k, x = map(int, input().split())
    if x > k * k:
        print(2*k-1)
        t -= 1
        continue

    def prefix(m):
        if m <= k:
            return m * (m+1) // 2
        total = k * (k + 1) // 2
        r = m - k
        total += r * (2 * k - r - 1) // 2
        return total

    lo = 1
    hi = 2*k-1

    while lo < hi:
        mid = (lo + hi) // 2
        if prefix(mid) >= x:
            hi = mid 
        else:
            lo = mid + 1
    print(lo)
    
    t -= 1
