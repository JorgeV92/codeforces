"""
CSES 1705 - Forbidden Cities
https://cses.fi/problemset/task/1705

PROBLEM
Given a connected undirected graph, answer queries (a, b, c): can we travel
from a to b without visiting c? If either endpoint equals c, the answer is NO.
There can be 100,000 vertices, 200,000 edges, and 100,000 queries. Running a
fresh BFS/DFS for every forbidden city costs O(q * (n + m)), which is too slow.
Instead, preprocess the components created by removing each possible city.

TECHNIQUES: DFS LOW-LINK VALUES, ARTICULATION POINTS, PREORDER INTERVALS,
           BINARY SEARCH, AND AN EXPLICIT STACK

1. DFS discovery times and low-link values
   tin[v] is the discovery time of v. low[v] is the smallest discovery time
   reachable by descending zero or more DFS-tree edges from v and then taking
   at most one back edge. Initially low[v] = tin[v].
   - An edge to an already visited neighbor u updates low[v] with tin[u].
   - After a DFS child u finishes, update low[v] with low[u].
   Skip the reverse of the edge that discovered v. Edge IDs ensure that a
   parallel edge is still processed. Self-loops do not change the result.

2. Which components survive when c is removed?
   Consider a direct DFS child u of c:
   - low[u] >= tin[c]: u's subtree has no back edge to a STRICT ancestor of c,
     so deleting c separates this whole subtree into its own component.
     Equality also separates it: an edge back to c is useless once c is gone.
   - low[u] < tin[c]: the subtree can escape to an ancestor without using c,
     so it stays connected to the component containing c's parent.
   Vertices outside c's subtree also stay in the parent-side component.
   Label that component 0 and give each separated subtree a positive ID.
   These labels are meaningful only for the particular forbidden city c.

   If c is the DFS root, every child satisfies low[u] >= tin[c]. Each child
   subtree therefore gets its own component, and component 0 is empty. The
   same rule handles the root, so no separate articulation-point flags are
   needed. If a == b != c, the zero-edge route is valid.

3. Store separated subtrees as intervals
   DFS discovers a subtree consecutively. At the moment u finishes, its
   vertices have discovery times in [tin[u], timer), where timer is the count
   of vertices discovered so far. For every separated child u of c, append
   tin[u] to cut_starts[c] and timer to cut_ends[c].
   Direct children finish in discovery order, so these intervals are already
   sorted and disjoint. There are at most n - 1 intervals in total: each
   DFS-tree edge can contribute just one. No sorting or ancestor table is
   needed, and each city only stores the branches relevant to its removal.

4. Classify each query endpoint using binary search
   bisect_right(starts, tin[x]) - 1 finds the last interval starting at or
   before x's discovery time. If x also lies before that interval's end, its
   component ID is the interval's index + 1. Otherwise its component ID is 0.
   First reject a == c or b == c. Then answer YES exactly when a and b have
   equal component IDs after removing c.

   Example: on the chain 1--2--3--4 rooted at 1, deleting 2 separates {3, 4}.
   Thus query (1, 4, 2) gives NO, and query (3, 4, 2) gives YES.

CORRECTNESS
An undirected DFS has no edges between different child subtrees: such an edge
would have caused one endpoint to be discovered from the other subtree.
Consequently, a child subtree can leave its branch without c exactly when a
back edge reaches a strict ancestor of c, which is equivalent to
low[child] < tin[c]. A separated subtree remains connected by its tree edges.
Every escaping subtree joins the ancestor side, which itself remains
connected by tree edges. Thus the intervals and component 0 describe exactly
the components after deleting c. A route avoiding c exists if and only if
both allowed endpoints receive the same component ID.

COMPLEXITY AND PYTHON DETAILS
Preprocessing takes O(n + m) time and space. A query takes O(log(k_c + 1)),
where k_c is the number of separated child intervals for c, at worst O(log n).
Total time is O(n + m + q log n). The graph and preprocessing use O(n + m)
space; buffering output adds O(q), for O(n + m + q) total space.
An explicit stack avoids Python's recursion limit on a chain of 100,000
cities. next_edge[v] records where DFS(v) should resume; finishing a vertex
propagates its low-link value and records its subtree's exclusive end.
Buffered input, batched output, and the standard-library bisect_right keep
the query overhead small.
"""

import sys
from bisect import bisect_right


def component_id(entry, starts, ends):
    """Return the component containing this discovery time after the deletion."""
    index = bisect_right(starts, entry) - 1
    if index >= 0 and entry < ends[index]:
        return index + 1
    return 0


def main():
    read = sys.stdin.buffer.readline
    first_line = read()
    if not first_line:
        return
    n, m, q = map(int, first_line.split())

    graph = [[] for _ in range(n + 1)]
    for edge_id in range(m):
        a, b = map(int, read().split())
        graph[a].append((b, edge_id))
        graph[b].append((a, edge_id))

    tin = [-1] * (n + 1)
    low = [0] * (n + 1)
    parent = [0] * (n + 1)
    parent_edge = [-1] * (n + 1)
    next_edge = [0] * (n + 1)
    cut_starts = [[] for _ in range(n + 1)]
    cut_ends = [[] for _ in range(n + 1)]

    # One DFS visits every city because the input graph is connected.
    tin[1] = low[1] = 0
    timer = 1
    stack = [1]

    while stack:
        v = stack[-1]
        index = next_edge[v]
        if index == len(graph[v]):
            # All descendants have finished: finalize v and return to its parent.
            stack.pop()
            p = parent[v]
            if p:
                if low[v] >= tin[p]:
                    cut_starts[p].append(tin[v])
                    cut_ends[p].append(timer)
                if low[v] < low[p]:
                    low[p] = low[v]
            continue

        u, edge_id = graph[v][index]
        next_edge[v] = index + 1
        if edge_id == parent_edge[v]:
            continue

        if tin[u] == -1:
            parent[u] = v
            parent_edge[u] = edge_id
            tin[u] = low[u] = timer
            timer += 1
            stack.append(u)
        elif tin[u] < low[v]:
            # An already visited descendant has a larger tin and cannot help.
            low[v] = tin[u]

    answers = []
    for _ in range(q):
        a, b, c = map(int, read().split())
        if a == c or b == c:
            answers.append("NO")
        elif a == b or not cut_starts[c]:
            answers.append("YES")
        else:
            starts = cut_starts[c]
            ends = cut_ends[c]
            same_component = (
                component_id(tin[a], starts, ends)
                == component_id(tin[b], starts, ends)
            )
            answers.append("YES" if same_component else "NO")

    sys.stdout.write("\n".join(answers) + "\n")


if __name__ == "__main__":
    main()
