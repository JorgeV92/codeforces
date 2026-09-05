/*
CSES 1705 - Forbidden Cities
https://cses.fi/problemset/task/1705

PROBLEM
Given a connected undirected graph, answer queries (a, b, c): can we travel
from a to b without visiting c? If either endpoint equals c, the answer is NO.
There can be 100,000 vertices, 200,000 edges, and 100,000 queries, so running
a new BFS/DFS after removing c for every query would be too slow:
O(q * (n + m)). Instead, preprocess all possible forbidden vertices together.

TECHNIQUES: DFS LOW-LINK VALUES, ARTICULATION POINTS, PREORDER INTERVALS,
           BINARY SEARCH, AND AN EXPLICIT STACK

1. Build a DFS tree and compute low-link values.
   tin[v] is the discovery time of v. low[v] is the smallest discovery time
   reachable by descending zero or more DFS-tree edges from v and then taking
   at most one back edge. Initially low[v] = tin[v].
   - For a visited neighbor u, update low[v] with tin[u].
   - After finishing a DFS child u, update low[v] with low[u].
   Skip the reverse of the edge that discovered v. Edge IDs distinguish it
   from any parallel edges. Self-loops do not affect the result.

2. Describe the components that remain when a vertex c is removed.
   For each direct DFS child u of c:
   - If low[u] >= tin[c], the subtree of u becomes its own component.
     It has no back edge to a STRICT ancestor of c. An edge back to c itself
     cannot help because c is forbidden; this explains the >= comparison.
   - If low[u] < tin[c], this subtree can escape to an ancestor of c without
     visiting c. It joins the component containing the parent of c.
   All vertices outside c's subtree also belong to that latter component.
   Call it component 0. Each separated child subtree gets a distinct positive
   component ID. These IDs are local to the chosen forbidden vertex c.

   For the DFS root, every child satisfies low[u] >= tin[root], so each child
   subtree gets its own component and component 0 is empty. This handles the
   root automatically, without separately marking articulation points.

3. Represent separated subtrees as sorted, disjoint intervals.
   DFS visits every subtree consecutively. When u finishes, its vertices have
   discovery times in [tin[u], timer), where timer is the number of vertices
   discovered so far. If u is a separated child of c, store this interval in
   cut_starts[c] and cut_ends[c]. Direct children finish in discovery order,
   so the intervals are already sorted and never overlap. Their total number
   is at most n - 1, since each DFS-tree edge contributes at most one interval.

4. Answer a query using two binary searches.
   To classify x != c, find the last stored interval whose start <= tin[x].
   If tin[x] is also less than its end, x belongs to that separated component;
   otherwise x belongs to component 0. After rejecting a == c or b == c,
   answer YES exactly when a and b receive the same component ID.

   Example: on the chain 1--2--3--4 rooted at 1, removing 2 separates the
   subtree {3, 4}. Thus (1, 4, 2) is NO, while (3, 4, 2) is YES.

WHY THIS IS CORRECT
In an undirected DFS, there are no edges between different child subtrees:
such an edge would have caused one endpoint to be discovered from the other
subtree. A child subtree can therefore leave its branch after deleting c only
through a back edge to a strict ancestor of c, which exists exactly when its
low-link value is < tin[c]. A separated subtree remains internally connected
by its tree edges. All escaping subtrees connect to the ancestor side, which
also remains connected by tree edges. The stored intervals therefore describe
exactly the components of the graph without c. Two allowed endpoints have a
route between them if and only if their component IDs match.

COMPLEXITY AND IMPLEMENTATION
Preprocessing: O(n + m) time and space.
Each query: O(log(k_c + 1)), where k_c is the number of stored intervals for c;
at worst O(log n). Total: O(n + m + q log n) time, O(n + m) space.
An explicit DFS stack avoids stack overflow on a chain of 100,000 cities.
Each stack frame resumes at next_edge[v], allowing low-link values and
interval ends to be finalized only after all descendants have been processed.
Queries allow a == b: the zero-edge route is valid whenever a != c.
*/

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    if (!(cin >> n >> m >> q)) return 0;

    vector<vector<pair<int, int>>> graph(n + 1);
    for (int edge_id = 0; edge_id < m; ++edge_id) {
        int a, b;
        cin >> a >> b;
        graph[a].emplace_back(b, edge_id);
        graph[b].emplace_back(a, edge_id);
    }

    vector<int> tin(n + 1, -1), low(n + 1);
    vector<int> parent(n + 1, 0), parent_edge(n + 1, -1);
    vector<int> next_edge(n + 1, 0);
    vector<vector<int>> cut_starts(n + 1), cut_ends(n + 1);
    vector<int> stack;
    stack.reserve(n);

    // The input graph is connected, so one DFS from city 1 visits every city.
    int timer = 1;
    tin[1] = low[1] = 0;
    stack.push_back(1);

    while (!stack.empty()) {
        int v = stack.back();
        if (next_edge[v] == static_cast<int>(graph[v].size())) {
            // Finishing v is the iterative equivalent of returning from DFS(v).
            stack.pop_back();
            int p = parent[v];
            if (p != 0) {
                if (low[v] >= tin[p]) {
                    cut_starts[p].push_back(tin[v]);
                    cut_ends[p].push_back(timer);
                }
                low[p] = min(low[p], low[v]);
            }
            continue;
        }

        auto [u, edge_id] = graph[v][next_edge[v]++];
        if (edge_id == parent_edge[v]) continue;

        if (tin[u] == -1) {
            parent[u] = v;
            parent_edge[u] = edge_id;
            tin[u] = low[u] = timer++;
            stack.push_back(u);
        } else {
            // Edges to descendants cannot lower low[v]; back edges can.
            low[v] = min(low[v], tin[u]);
        }
    }

    auto component_id = [&](int vertex, int forbidden) {
        const auto& starts = cut_starts[forbidden];
        int index = static_cast<int>(
            upper_bound(starts.begin(), starts.end(), tin[vertex]) - starts.begin()
        ) - 1;
        if (index >= 0 && tin[vertex] < cut_ends[forbidden][index]) {
            return index + 1;
        }
        return 0;
    };

    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == c || b == c) {
            cout << "NO\n";
        } else if (component_id(a, c) == component_id(b, c)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
