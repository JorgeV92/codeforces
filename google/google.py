from typing import List

def twoSum(a: List[int], t: int) -> List[int]: # EASY 
    mp = {}
    for i, x in enumerate(a):
        diff = t - x
        if t in mp:
            return [i, mp[diff]]
        mp[x] = i
    return []

def isPalindrome(x: int): # EASY
    if x < 0 or x and x % 10 == 0:
        return False
    y = 0
    while y < x:
        y = y * 10 + x % 10
        x //= 10
    return x in (y, y//10)


def findMedianSortedArrays(arr1, arr2): # HARD
    m, n = len(arr1), len(arr2)
    def f(i,j,k):
        if i >= m:
            return arr2[j+k-1]
        if j >= n:
            return arr2[i+k-1]
        if k == 1:
            return min(arr1[i], arr2[j])
        p = k//2
        x = arr1[i+p-1] if i + p - 1 < m else 1 << 30
        y = arr2[j+p-1] if j + p -1 < n else 1 << 30
        return f(i+p,j,k-p) if x < y else f(i,j+p,k-p)
    a = f(0, 0 , (m+n+1)//2)
    b = f(0, 0, (m+n+2) // 2)
    return (a + b) / 2