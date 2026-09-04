"""
Logic:
Suppose S[i] == T[j], where i > 0 and j < len(T) - 1. Then

    S[:i + 1] + T[j + 1:]

has two valid splits: S[:i] + T[j:] and S[:i + 1] + T[j + 1:].
Both parts in both splits are non-empty, so this is an interesting
abbreviation.

Conversely, take any interesting abbreviation and two of its split
points. At the first position where one split still uses T while the
other already uses S, the corresponding characters of S and T must
match. Therefore, every valid answer can be represented by a pair
(i, j) of the form above.

The resulting length is (i + 1) + (len(T) - j - 1) = i + len(T) - j.
For each letter, this is minimized by using its earliest occurrence in
S after index 0 and its latest occurrence in T before the final index.

Time:  O(len(S) + len(T))
Space: O(1) auxiliary space (only 26 stored positions)
"""

import sys


def solve() -> None:
    s = sys.stdin.buffer.readline().strip()
    t = sys.stdin.buffer.readline().strip()

    last = [-1] * 26
    for j in range(len(t) - 1): last[t[j] - ord("a")] = j

    best_i = -1
    best_j = -1
    best_length = len(s) + len(t) + 1

    for i in range(1, len(s)):
        j = last[s[i] - ord("a")]
        length = i + len(t) - j

        if j != -1 and length < best_length:
            best_length = length
            best_i = i
            best_j = j

    if best_i == -1: print(-1)
    else: sys.stdout.buffer.write(s[: best_i + 1] + t[best_j + 1 :] + b"\n")

if __name__ == "__main__":
    solve()
