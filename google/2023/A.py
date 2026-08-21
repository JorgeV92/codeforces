import sys


def preprocess_tree(n, parents):
    graph = [[] for _ in range(n)]

    for v, u in enumerate(parents):
        u -= 1
        graph[v].append(u)
        graph[u].append(v)

    parent = [-1] * n
    order = [0]
    parent[0] = 0

    # Build a DFS order.
    for cur in order:
        for nxt in graph[cur]:
            if parent[nxt] != -1:
                continue

            parent[nxt] = cur
            order.append(nxt)

    subtree_size = [1] * n
    loc_dist = [0] * n

    # Process nodes from children to parents.
    # This computes subtree sizes and loc_dist[0].
    for cur in reversed(order[1:]):
        p = parent[cur]

        subtree_size[p] += subtree_size[cur]
        loc_dist[0] += subtree_size[cur]

    # Reroot to calculate the distance sum for every node.
    for cur in order[1:]:
        p = parent[cur]

        loc_dist[cur] = (
            loc_dist[p]
            - subtree_size[cur]
            + (n - subtree_size[cur])
        )

    # Each unordered pair was counted twice.
    total_pair_distance = sum(loc_dist) // 2

    return loc_dist, total_pair_distance


def solve():
    data = list(map(int, sys.stdin.buffer.read().split()))
    it = iter(data)

    test_cases = next(it)
    output = []

    for case_number in range(1, test_cases + 1):
        W = next(it)
        E = next(it)
        C = next(it)

        west_parents = [next(it) for _ in range(W - 1)]
        east_parents = [next(it) for _ in range(E - 1)]

        west_dist, west_total = preprocess_tree(W, west_parents)
        east_dist, east_total = preprocess_tree(E, east_parents)

        total_stations = W + E
        number_of_pairs = total_stations * (total_stations - 1) // 2

        answers = []

        for _ in range(C):
            a = next(it) - 1
            b = next(it) - 1

            cross_distance = (
                west_dist[a] * E
                + W * E
                + east_dist[b] * W
            )

            total_distance = (
                west_total
                + east_total
                + cross_distance
            )

            average = total_distance / number_of_pairs
            answers.append(f"{average:.12f}")

        output.append(
            f"Case #{case_number}: " + " ".join(answers)
        )

    sys.stdout.write("\n".join(output))


if __name__ == "__main__":
    solve()
