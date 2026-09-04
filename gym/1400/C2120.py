"""
Logic:
For every vertex v, 1 <= d(v) <= v, so a valid sum must be in
[n, 1 + 2 + ... + n]. These bounds are also sufficient.

1. If n <= m <= 2n - 1, choose root r = m - n + 1. Connect r to
   vertex 1 and connect every other vertex to 1 (unless r = 1, in
   which case every other vertex is connected directly to the root).
   The root contributes r and all other vertices contribute 1, giving
   r + n - 1 = m.

2. If m > 2n - 1, choose n as the root. Initially connect vertex 1
   to n and every vertex i in [2, n - 1] to 1. The sum is 2n - 1.
   Moving i from being a child of 1 to being a child of n changes its
   divineness from 1 to i, increasing the sum by i - 1. Thus, we only
   need to express m - (2n - 1) as a subset sum of 1, 2, ..., n - 2.
   Greedily taking these values from largest to smallest always works,
   because consecutive values 1..k can form every sum from 0 through
   k(k + 1) // 2.

Each construction is connected, acyclic, and contains exactly n - 1
edges.

Time:  O(n) per test case, which is optimal because n - 1 edges are output.
Space: O(sum(n)) for buffered output across all test cases.
"""

import sys


def solve() -> None:
    data = list(map(int, sys.stdin.buffer.read().split()))
    test_cases = data[0]
    position = 1
    output = []

    for _ in range(test_cases):
        n, m = data[position], data[position + 1]
        position += 2

        maximum_sum = n * (n + 1) // 2
        if m < n or m > maximum_sum:
            output.append("-1")
            continue

        if m <= 2 * n - 1:
            root = m - n + 1
            output.append(str(root))

            if root == 1:
                for vertex in range(2, n + 1):
                    output.append(f"1 {vertex}")
            else:
                output.append(f"{root} 1")
                for vertex in range(2, n + 1):
                    if vertex != root:
                        output.append(f"1 {vertex}")
            continue

        root = n
        remaining = m - (2 * n - 1)

        output.append(str(root))
        output.append(f"{root} 1")

        for vertex in range(n - 1, 1, -1):
            increase = vertex - 1
            if remaining >= increase:
                output.append(f"{root} {vertex}")
                remaining -= increase
            else:
                output.append(f"1 {vertex}")

    sys.stdout.write("\n".join(output))


if __name__ == "__main__":
    solve()
