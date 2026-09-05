"""
CSES 1705 - Forbidden Cities: block-cut tree + binary-lifting LCA
https://cses.fi/problemset/task/1705

PROBLEM AND IDEA
Each query asks whether a and b remain connected after city c is deleted.
Running a fresh graph search per query would take O(q * (n + m)). Instead,
turn the graph's articulation structure into a tree. The query then becomes:
does city c lie on the unique tree path between cities a and b?

TECHNIQUES
Recursive Tarjan DFS, low-link values, an edge stack, vertex-biconnected
components, an expanded block-cut tree, recursive tree DFS, subtree intervals,
and lowest common ancestors (LCA) with binary lifting.

1. EXTRACT BICONNECTED BLOCKS
   discovered[v] is the discovery time of v. low[v] is the earliest discovery
   time reachable from v's DFS subtree via a back edge, also allowing v itself.
   During recursive DFS, push tree edges and back edges to strict ancestors
   onto pending_edges. When a child u returns:
       low[v] = min(low[v], low[u]).
   If low[u] >= discovered[v], this branch cannot reach a strict ancestor of
   v. Pop edges through the tree edge (v, u), inclusive: these edges form one
   biconnected block. Equality is included because reaching v itself does not
   bypass v if it is forbidden. Bridges become blocks with two vertices.
   Each edge is pushed and popped at most once. Edge IDs distinguish parallel
   roads; self-loops have no effect on connectivity and need no block.

2. KEEP EVERY ORIGINAL CITY IN THE BLOCK-CUT TREE
   Original cities keep indices 0..n-1. For each block, append one new node
   connected to every distinct city in that block. A last_block array prevents
   duplicate links when several extracted edges share an endpoint.

   This is an expanded form of the usual block-cut tree: articulation cities
   join multiple blocks, while non-articulation cities remain as leaves of
   their sole block. It avoids both a separate city-to-block ID mapping and
   explicit articulation-point flags.

   Example: triangles {1,2,3} and {3,4,5} produce two block nodes connected
   through city 3. Cities 1 and 2 attach to the first block, and 4 and 5 to
   the second. Removing city 3 blocks 1 -> 5 but still allows 1 -> 2.

   Because the original graph is connected, this incidence structure is a
   tree. If B blocks are extracted, there are T = n + B nodes and T - 1 tree
   edges. Each block closes at a distinct DFS-tree edge, so B <= n - 1 and
   T <= 2n - 1. For one city, the tree consists of that city alone.

3. PREPROCESS ANCESTORS WITH A SECOND RECURSIVE DFS
   Root the tree at city 0. Compute depth, parent, and subtree discovery-time
   intervals [entered[v], exited[v]). Vertex v is an ancestor of x exactly
   when entered[v] <= entered[x] < exited[v].
   Build up[j][v] = the ancestor of v after 2**j parent steps. Set the root's
   parent to itself. Use T.bit_length() levels, based on the constructed tree,
   and access only levels 0 through len(up)-1. Binary lifting finds an LCA in
   O(log T). Compact array('i') rows reduce the ancestor table's memory use.

4. USE ONE LCA TO TEST THE FORBIDDEN CITY
   Let w = LCA(a, b). The path a -> b consists of the chains a -> w and b -> w.
   Thus c lies on the path precisely when BOTH conditions hold:
   - c is an ancestor of a or an ancestor of b;
   - depth[c] >= depth[w], so c is not above the path's highest vertex.
   If the first condition fails, skip the LCA calculation altogether.
   Answer NO if c is on the path, and YES otherwise. Forbidden endpoints are
   rejected immediately; a == b != c permits the zero-edge route.

CORRECTNESS
Within a biconnected block, removing one vertex leaves all surviving vertices
connected. A bridge block also satisfies this statement: deleting an endpoint
leaves just one vertex. Blocks can meet only at articulation points, so graph
connectivity after deleting c matches connectivity among the city nodes after
deleting c from the expanded block-cut tree. A tree has a unique path between
two vertices; removing c destroys that connection exactly when c is on the
path. The ancestor-and-LCA condition checks exactly those path vertices.

COMPLEXITY AND RECURSIVE PYTHON
Block construction: O(n + m) time and space.
LCA preprocessing: O(T log T) time and space.
Queries: O(log T) each, at most O(log n) for n > 1.
Total: O(m + n log n + q log n) time and O(m + n log n + q) space, including
the buffered answers. The n = 1 case takes constant preprocessing/query time.

Both graph traversals use actual recursive calls. A chain of n cities becomes
a tree of 2n - 1 nodes, so sys.setrecursionlimit(2*n + 1000) provides enough
Python call depth. On interpreters where Python recursion uses native stack
space, that limit alone is insufficient. The solver therefore runs in one
worker thread with a requested 256 MiB stack. This thread provides stack
capacity; it does not parallelize the algorithm. The original graph is freed
before the ancestor table is allocated. pending_edges is the component edge
stack required by Tarjan's algorithm, not an iterative DFS implementation.
"""

import sys
import threading
from array import array


class BlockCutBuilder:
    def __init__(self, n):
        self.graph = [[] for _ in range(n)]
        self.roads = []
        self.tree = [[] for _ in range(n)]
        self.discovered = [-1] * n
        self.low = [0] * n
        self.pending_edges = []
        self.last_block = [-1] * n
        self.timer = 0

    def add_road(self, a, b):
        edge = len(self.roads)
        self.roads.append((a, b))
        self.graph[a].append((b, edge))
        self.graph[b].append((a, edge))

    def _finish_block(self, first_edge):
        block = len(self.tree)
        self.tree.append([])
        while True:
            edge = self.pending_edges.pop()
            for city in self.roads[edge]:
                if self.last_block[city] != block:
                    self.last_block[city] = block
                    self.tree[city].append(block)
                    self.tree[block].append(city)
            if edge == first_edge:
                break

    def _visit(self, v, incoming_edge):
        self.discovered[v] = self.low[v] = self.timer
        self.timer += 1
        for u, edge in self.graph[v]:
            if edge == incoming_edge:
                continue
            if self.discovered[u] == -1:
                self.pending_edges.append(edge)
                self._visit(u, edge)
                if self.low[u] < self.low[v]:
                    self.low[v] = self.low[u]
                if self.low[u] >= self.discovered[v]:
                    self._finish_block(edge)
            elif self.discovered[u] < self.discovered[v]:
                # The reverse direction would duplicate this back edge.
                self.pending_edges.append(edge)
                if self.discovered[u] < self.low[v]:
                    self.low[v] = self.discovered[u]

    def build(self):
        self._visit(0, -1)
        return self.tree


class TreePaths:
    def __init__(self, tree):
        self.tree = tree
        size = len(tree)
        self.entered = [0] * size
        self.exited = [0] * size
        self.depth = [0] * size
        self.up = [array("i", [0]) * size]
        self.timer = 0
        self._visit(0, 0)
        for _ in range(1, size.bit_length()):
            previous = self.up[-1]
            self.up.append(array("i", (previous[previous[v]] for v in range(size))))

    def _visit(self, v, parent):
        self.entered[v] = self.timer
        self.timer += 1
        self.up[0][v] = parent
        for u in self.tree[v]:
            if u != parent:
                self.depth[u] = self.depth[v] + 1
                self._visit(u, v)
        self.exited[v] = self.timer

    def _lca(self, a, b):
        entered = self.entered
        exited = self.exited
        if entered[a] <= entered[b] < exited[a]:
            return a
        if entered[b] <= entered[a] < exited[b]:
            return b
        for ancestors in reversed(self.up):
            candidate = ancestors[a]
            if not (entered[candidate] <= entered[b] < exited[candidate]):
                a = candidate
        return self.up[0][a]

    def on_path(self, a, b, c):
        entered = self.entered
        exited = self.exited
        if not (entered[c] <= entered[a] < exited[c]
                or entered[c] <= entered[b] < exited[c]):
            return False
        return self.depth[c] >= self.depth[self._lca(a, b)]


def main():
    read = sys.stdin.buffer.readline
    first_line = read()
    if not first_line:
        return
    n, m, q = map(int, first_line.split())
    sys.setrecursionlimit(2 * n + 1000)

    builder = BlockCutBuilder(n)
    for _ in range(m):
        a, b = map(int, read().split())
        builder.add_road(a - 1, b - 1)
    tree = builder.build()
    del builder  # The original adjacency lists and component buffers are done.
    paths = TreePaths(tree)

    answers = []
    for _ in range(q):
        a, b, c = map(int, read().split())
        a -= 1
        b -= 1
        c -= 1
        blocked = a == c or b == c or paths.on_path(a, b, c)
        answers.append("NO" if blocked else "YES")
    sys.stdout.write("\n".join(answers) + "\n")


if __name__ == "__main__":
    threading.stack_size(256 * 1024 * 1024)
    worker = threading.Thread(target=main)
    worker.start()
    worker.join()
