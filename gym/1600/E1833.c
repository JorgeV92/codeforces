#include <stdio.h>
#include <stdlib.h>

int find(int x, int* parent) {
    if (parent[x] != x) parent[x] = find(parent[x], parent);
    return parent[x];
}

void unite(int a, int b, int* parent, int* size) {
    a = find(a, parent); b = find(b, parent);
    if (a==b) return;
    if (size[a] < size[b]) {
        int tmp = a;
        a = b; b = tmp;
    }
    parent[b] = a;
    size[a] += size[b];
}

int main() {
    int t; scanf("%d", &t); 
    while (t--) {
        int n; scanf("%d", &n);
        int* a = malloc(n*sizeof(int));
        int* p = malloc(n*sizeof(int));
        int* sz = malloc(n*sizeof(n));
        int* deg = calloc(n, sizeof(n));

        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            --a[i];
            p[i] = i;
            sz[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            int j= a[i];
            if (a[j] == i && i > j) continue;
            unite(i, j, p, sz);
            deg[i]++;
            deg[j]++;
        }
        int* is_cycle = malloc(n*sizeof(int));
        for (int i = 0; i < n; i++) {
            is_cycle[i] = 1;
        }
        for (int i = 0; i < n; ++i) {
            int root = find(i, p);
            if (deg[i] != 2) is_cycle[root] = 0;
        }
        int comp = 0;
        int ccycles = 0;
        for (int i = 0; i < n; ++i) {
            if (find(i, p) == i) {
                comp++;
                if (is_cycle[i]) ccycles++;
            }
        }
        int mx = comp;
        int mn = ccycles;
        if (comp > ccycles) mn++;
        printf("%d %d\n", mn, mx);
        free(a);
        free(p);
        free(sz);
        free(deg);
        free(is_cycle);
    }

    return 0;
}