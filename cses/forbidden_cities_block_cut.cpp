/*
CSES 1705 - Forbidden Cities: block-cut tree + binary-lifting LCA
https://cses.fi/problemset/task/1705

PROBLEM AND STRATEGY
For each query (a, b, c), decide whether a and b remain connected after city c
is removed. Searching the graph for every query is too expensive. Instead,
describe the graph's articulation structure as a tree and test whether c lies
on the unique tree path between a and b.

TECHNIQUES
Recursive Tarjan DFS, discovery times and low-link values, an edge stack,
vertex-biconnected components, a block-cut tree, DFS subtree intervals, and
lowest common ancestors (LCA) with binary lifting.

1. FIND BICONNECTED BLOCKS WITH AN EDGE STACK
   discovered[v] records when DFS first visits v. low[v] is the smallest
   discovery time reachable from v's DFS subtree using a back edge, also
   allowing v itself. Push every tree edge and every back edge to an ancestor
   onto pending_edges. Each undirected edge is pushed at most once.

   After visiting a DFS child u of v, low[u] >= discovered[v] means that u's
   branch cannot reach a strict ancestor of v. This closes a biconnected block:
   pop edges through the tree edge (v, u), inclusive. Their endpoints are the
   vertices of that block. The >= matters because reaching v itself does not
   bypass v when it is removed. A bridge forms a block with two vertices.
   Edge IDs allow parallel roads; self-loops can be ignored for connectivity.

2. BUILD AN EXPANDED BLOCK-CUT TREE
   Keep all original cities as nodes 0..n-1. For every block, append a new node
   and connect it to every distinct city in that block. last_block[city]
   prevents adding a city twice when several popped edges share an endpoint.

   In the usual compressed block-cut tree, only articulation points keep
   their own nodes; other cities map to their block. Here those other cities
   remain as leaves. This equivalent representation needs no city-ID mapping
   and no separate articulation-point array.

   For two triangles {1,2,3} and {3,4,5}, city 3 links the two block nodes;
   cities 1,2 are leaves of the first block and 4,5 of the second. Removing 3
   separates 1 from 5, but does not separate 1 from 2.

   The input graph is connected, so the incidence structure is a tree. If
   there are B blocks, it has T = n + B nodes and T - 1 edges. Since every
   block closes at a distinct DFS-tree edge, B <= n - 1. A single city simply
   produces a one-node tree.

3. PREPROCESS TREE PATHS WITH A SECOND RECURSIVE DFS
   Root the new tree at city 0. Record depth, direct parent, and the half-open
   subtree interval [entered[v], exited[v]). Then:
       ancestor(v, x) iff entered[v] <= entered[x] < exited[v].
   Build up[j][v], the ancestor of v after 2^j steps. The number of levels is
   computed from T, not from the original graph size. Valid indices are
   0..levels-1. Binary lifting finds LCA(a, b) in O(log T).

4. ANSWER WITH ONE LCA QUERY
   Let w = LCA(a, b). The a-b path is the union of the ancestor chains from
   a to w and b to w. Therefore c lies on that path exactly when:
       (ancestor(c, a) or ancestor(c, b)) and depth[c] >= depth[w].
   If c is not an ancestor of either endpoint, no LCA call is needed.
   Print NO when c is on the path, YES otherwise. Rejecting a == c or b == c
   explicitly also handles forbidden endpoints. If a == b != c, answer YES.

WHY THE REDUCTION IS CORRECT
A biconnected block stays connected between its surviving vertices after
one city is removed; for a bridge block, at most one vertex survives if an
endpoint is removed. Distinct blocks meet only at articulation points. Thus
a graph route avoiding c exists exactly when its endpoint cities remain
connected in the expanded block-cut tree with node c removed. In a tree,
removing a node separates two other nodes precisely when it lies on their
unique path. The LCA condition checks exactly this property.

COMPLEXITY AND RECURSION
Block construction takes O(n + m) time and space. LCA preprocessing takes
O(T log T) time and space, and each query takes O(log T) in the worst case.
With T <= 2n - 1, total time is O(m + n log n + q log n), and space is
O(m + n log n). For n = 1, preprocessing and each query are constant time.
Both DFS traversals are recursive. A chain can produce nearly 2n recursive
tree calls, so on POSIX systems the program requests a larger process stack,
up to the system's hard limit. pending_edges is Tarjan's component stack;
it does not replace recursive DFS calls.
*/

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using namespace std;

class BlockCutBuilder {
    vector<vector<pair<int, int>>> graph;
    vector<pair<int, int>> roads;
    vector<vector<int>> tree;
    vector<int> discovered, low, pending_edges, last_block;
    int timer = 0;

    void finish_block(int first_edge) {
        int block = static_cast<int>(tree.size());
        tree.emplace_back();
        while (true) {
            int edge = pending_edges.back();
            pending_edges.pop_back();
            auto [a, b] = roads[edge];
            for (int city : {a, b}) {
                if (last_block[city] != block) {
                    last_block[city] = block;
                    tree[city].push_back(block);
                    tree[block].push_back(city);
                }
            }
            if (edge == first_edge) break;
        }
    }

    void visit(int v, int incoming_edge) {
        discovered[v] = low[v] = timer++;
        for (auto [u, edge] : graph[v]) {
            if (edge == incoming_edge) continue;
            if (discovered[u] == -1) {
                pending_edges.push_back(edge);
                visit(u, edge);
                low[v] = min(low[v], low[u]);
                if (low[u] >= discovered[v]) finish_block(edge);
            } else if (discovered[u] < discovered[v]) {
                // Process a back edge only from its descendant endpoint.
                pending_edges.push_back(edge);
                low[v] = min(low[v], discovered[u]);
            }
        }
    }

public:
    explicit BlockCutBuilder(int n)
        : graph(n), tree(n), discovered(n, -1), low(n), last_block(n, -1) {}

    void add_road(int a, int b) {
        int edge = static_cast<int>(roads.size());
        roads.emplace_back(a, b);
        graph[a].emplace_back(b, edge);
        graph[b].emplace_back(a, edge);
    }

    vector<vector<int>> build() {
        visit(0, -1);
        return std::move(tree);
    }
};

class TreePaths {
    const vector<vector<int>>& tree;
    vector<vector<int>> up;
    vector<int> entered, exited, depth;
    int timer = 0;

    void visit(int v, int parent) {
        entered[v] = timer++;
        up[0][v] = parent;
        for (int u : tree[v]) {
            if (u == parent) continue;
            depth[u] = depth[v] + 1;
            visit(u, v);
        }
        exited[v] = timer;
    }

    bool ancestor(int v, int x) const {
        return entered[v] <= entered[x] && entered[x] < exited[v];
    }

    int lca(int a, int b) const {
        if (ancestor(a, b)) return a;
        if (ancestor(b, a)) return b;
        for (int level = static_cast<int>(up.size()) - 1; level >= 0; --level) {
            int candidate = up[level][a];
            if (!ancestor(candidate, b)) a = candidate;
        }
        return up[0][a];
    }

public:
    explicit TreePaths(const vector<vector<int>>& input_tree)
        : tree(input_tree), entered(tree.size()), exited(tree.size()),
          depth(tree.size()) {
        int size = static_cast<int>(tree.size());
        int levels = 1;
        while ((1LL << levels) <= size) ++levels;
        up.assign(levels, vector<int>(size));
        visit(0, 0);
        for (int level = 1; level < levels; ++level) {
            for (int v = 0; v < size; ++v) {
                up[level][v] = up[level - 1][up[level - 1][v]];
            }
        }
    }

    bool on_path(int a, int b, int c) const {
        if (!ancestor(c, a) && !ancestor(c, b)) return false;
        return depth[c] >= depth[lca(a, b)];
    }
};

void allow_deep_recursion() {
#if defined(__unix__) || defined(__APPLE__)
    rlimit limit;
    if (getrlimit(RLIMIT_STACK, &limit) == 0) {
        rlim_t wanted = 128ULL * 1024 * 1024;
        if (limit.rlim_max != RLIM_INFINITY) wanted = min(wanted, limit.rlim_max);
        if (limit.rlim_cur != RLIM_INFINITY && limit.rlim_cur < wanted) {
            limit.rlim_cur = wanted;
            setrlimit(RLIMIT_STACK, &limit);
        }
    }
#endif
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    allow_deep_recursion();

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> tree;
    {
        BlockCutBuilder builder(n);
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            builder.add_road(a - 1, b - 1);
        }
        tree = builder.build();
    } // Release the original graph before allocating the ancestor table.
    TreePaths paths(tree);

    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        --c;
        bool blocked = a == c || b == c || paths.on_path(a, b, c);
        cout << (blocked ? "NO\n" : "YES\n");
    }
    return 0;
}
