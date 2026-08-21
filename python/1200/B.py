def main():
    T = int(input())
    a = [int(int) for x in input().split()]
    mn = min(a)
    mx = max(a)
    ans = (mx - mn +1) / 2
    print(ans); print()

if __name__ == "__main__":
    main()
