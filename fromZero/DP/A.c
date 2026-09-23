#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m; scanf("%d %d", &n, &m);
    int *a = malloc(n * sizeof(int));
    int *pref = calloc(n+1, sizeof(int));
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) pref[i+1] = pref[i] + a[i];
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int l, r; scanf("%d %d", &l, &r);
        --l;
        int sum = pref[r] - pref[l];
        if (sum > 0) ans += sum;
    }
    printf("%d\n", ans);
    free(a);
    free(pref);

    return 0;
}