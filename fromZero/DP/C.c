#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    long long ans = 0;
    int neg =0 ;
    int zeros = 0;
    for (int i = 0; i < n; ++i)  {
        long long x; scanf("%lld", &x);
        if (x > 0) 
            ans += x - 1;
        else if (x < 0) {
            ans += -1 - x;
            neg++;
        }
        else {
            ans += 1;
            zeros++;
        }
    }
    if (neg % 2 == 1 && zeros == 0) ans += 2;
    printf("%lld\n", ans);

    return 0;
}