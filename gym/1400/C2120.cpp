/*
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
   k(k + 1) / 2.

Each construction is connected, acyclic, and contains exactly n - 1
edges.

Time:  O(n) per test case, which is optimal because n - 1 edges are output.
Space: O(1) auxiliary space (excluding the output stream).
*/

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, m;
        cin >> n >> m;

        const long long maximum_sum = n * (n + 1) / 2;
        if (m < n || m > maximum_sum) {
            cout << -1 << '\n';
            continue;
        }

        if (m <= 2 * n - 1) {
            const long long root = m - n + 1;
            cout << root << '\n';

            if (root == 1) {
                for (long long vertex = 2; vertex <= n; ++vertex) {
                    cout << 1 << ' ' << vertex << '\n';
                }
            } else {
                cout << root << ' ' << 1 << '\n';
                for (long long vertex = 2; vertex <= n; ++vertex) {
                    if (vertex != root) {
                        cout << 1 << ' ' << vertex << '\n';
                    }
                }
            }
            continue;
        }

        const long long root = n;
        long long remaining = m - (2 * n - 1);

        cout << root << '\n';
        cout << root << ' ' << 1 << '\n';

        for (long long vertex = n - 1; vertex >= 2; --vertex) {
            const long long increase = vertex - 1;
            if (remaining >= increase) {
                cout << root << ' ' << vertex << '\n';
                remaining -= increase;
            } else {
                cout << 1 << ' ' << vertex << '\n';
            }
        }
    }

    return 0;
}
