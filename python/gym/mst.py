# Minimum spanning trees
#
# MST

import heapq

def road_reparation_kruskal():
    class DSU:
        def __init__(self, n):
            self.n = n
            self.p = [i for i in range(n)]
            self.sz = [1] * n 

        def find(self, x):
            if self.p[x] != x:
                self.p[x] = self.find(self.p[x])
            return self.p[x]
        
        def union(self, x, y):
            rx = self.find(x)
            ry = self.find(y)
            if rx == ry:
                return False
            if self.sz[rx] < self.sz[ry]:
                rx, ry = ry, rx
            self.p[ry] = rx 
            self.sz[rx ]+= self.sz[ry]
            return True

    n, m = map(int, input().split())
    edges = []
    for _ in range(m):
        a, b, c = map(int, input().split())
        edges.append((c, a, b))

    edges.sort()    

    dsu = DSU(n)
    ans =0 
    used = 0
    for w, a, b in edges:
        a -= 1
        b -= 1
        if dsu.union(a, b):
            ans += w
            used += 1
    if used == n-1:
        print(ans)
    else:
        print('IMPOSSIBLE')

def road_reparation_prims():
    n, m = map(int, input().split())
    g = [[] for _ in range(n)]
    for _ in range(m):
        a,b,w = map(int,input().split())
        a -= 1; b -= 1 
        g[a].append((b, w))
        g[b].append((a, w))

    def prims():
        min_cost = 0
        dist = [float('inf')] * n
        dist[0] = 0
        pq = []
        heapq.heappush(pq, (0,0))
        vis = [False] * n
        added = 0
        while added < n:
            if not pq:
                return -1
            w, v = heapq.heappop(pq)
            if dist[v] < w:
                continue
            added += 1
            vis[v] = True
            min_cost += w
            for u, cc in g[v]:
                if not vis[u] and cc < dist[u]:
                    dist[u] = cc
                    heapq.heappush(pq, (cc, u))
        return min_cost

    mst_cost = prims()
    if mst_cost == -1:
        print("IMPOSSIBLE")
    else:
        print(mst_cost)

def google_kickstart_checksum():
    import sys
    class TensorView:
        def __init__(self, shape, strides, data, offset=0):
            self.shape = shape
            self.strides = strides
            self.data = data
            self.offset = offset

        def flatten_index(self, idx):
            res = self.offset

            for i in range(len(self.shape)):
                res += idx[i] * self.strides[i]

            return res

        def flatten_index_checked(self, idx):
            res = self.offset

            for i in range(len(self.shape)):
                assert 0 <= idx[i] < self.shape[i]
                res += idx[i] * self.strides[i]

            return res

        def __getitem__(self, idx):
            # Equivalent to:
            #
            # A[{i, j}]
            #
            # in the C++ version.
            if isinstance(idx, tuple):
                return self.data[self.flatten_index(idx)]

            # Equivalent to:
            #
            # A[i]
            #
            # which returns a lower-dimensional tensor_view.
            assert len(self.shape) > 0

            new_shape = self.shape[1:]
            new_strides = self.strides[1:]

            new_offset = self.offset + self.strides[0] * idx

            # If this was the final dimension, return the value.
            if len(new_shape) == 0:
                return self.data[new_offset]

            return TensorView(
                new_shape,
                new_strides,
                self.data,
                new_offset
            )

        def __setitem__(self, idx, value):
            if isinstance(idx, tuple):
                self.data[self.flatten_index(idx)] = value
                return

            # For a 1D view:
            #
            # row[j] = value
            if len(self.shape) == 1:
                pos = self.offset + idx * self.strides[0]
                self.data[pos] = value
                return

            raise TypeError("Use tuple indexing for multidimensional assignment")

        def at(self, idx):
            if isinstance(idx, tuple):
                return self.data[self.flatten_index_checked(idx)]

            assert 0 <= idx < self.shape[0]
            return self[idx]


    class Tensor:
        def __init__(self, shape, default=0):
            self.shape = list(shape)
            self.ndims = len(shape)

            self.strides = [0] * self.ndims

            if self.ndims > 0:
                self.strides[-1] = 1

                for i in range(self.ndims - 1, 0, -1):
                    self.strides[i - 1] = (
                        self.strides[i] * self.shape[i]
                    )

                self.length = self.strides[0] * self.shape[0]
            else:
                self.length = 1

            self.data = [default] * self.length

        def view(self):
            return TensorView(
                self.shape,
                self.strides,
                self.data
            )

        def __getitem__(self, idx):
            return self.view()[idx]

        def __setitem__(self, idx, value):
            self.view()[idx] = value

        def at(self, idx):
            return self.view().at(idx)


    # ---------------------------------------------------------
    # DSU
    # ---------------------------------------------------------

    class DSU:
        def __init__(self, n):
            # Same representation as the C++ code:
            #
            # negative -> root, abs(value) = component size
            # positive -> parent
            self.par = [-1] * n

        def find(self, a):
            while self.par[a] >= 0:
                if self.par[self.par[a]] >= 0:
                    self.par[a] = self.par[self.par[a]]

                a = self.par[a]

            return a

        def merge(self, a, b):
            a = self.find(a)
            b = self.find(b)

            if a == b:
                return False

            # par[root] is negative.
            # More negative = larger component.
            if self.par[a] > self.par[b]:
                a, b = b, a

            self.par[a] += self.par[b]
            self.par[b] = a

            return True


    def solve():
        input = sys.stdin.buffer.readline

        T = int(input())

        for case_num in range(1, T + 1):
            N = int(input())

            # --------------------------------------------------
            # Read A
            # --------------------------------------------------

            A = Tensor((N, N))

            for i in range(N):
                row = list(map(int, input().split()))

                for j in range(N):
                    A[i, j] = row[j]

            # --------------------------------------------------
            # Read B
            # --------------------------------------------------

            B = Tensor((N, N))

            for i in range(N):
                row = list(map(int, input().split()))

                for j in range(N):
                    B[i, j] = row[j]

            # Checksums
            R = list(map(int, input().split()))
            C = list(map(int, input().split()))

            # --------------------------------------------------
            # Bucket edges by weight
            #
            # vals[w] contains all cells having cost w.
            # This replaces sorting the edges.
            # --------------------------------------------------

            vals = [[] for _ in range(1001)]

            for i in range(N):
                for j in range(N):
                    vals[B[i, j]].append((i, j))

            # --------------------------------------------------
            # Bipartite graph:
            #
            # row vertices:
            #     0 ... N-1
            #
            # column vertices:
            #     N ... 2N-1
            # --------------------------------------------------

            V = 2 * N
            dsu = DSU(V)

            ans = 0

            # --------------------------------------------------
            # Maximum spanning forest Kruskal.
            #
            # Largest costs first.
            # --------------------------------------------------

            for v in range(1000, -1, -1):
                for i, j in vals[v]:

                    row_vertex = i
                    col_vertex = N + j

                    if not dsu.merge(row_vertex, col_vertex):
                        # This edge would create a cycle.
                        #
                        # Therefore this cell must be recovered
                        # manually, so we pay its cost.
                        ans += v

            print(f"Case #{case_num}: {ans}")

if __name__ == '__main__':
    road_reparation_kruskal()

        
