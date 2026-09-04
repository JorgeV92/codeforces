/*
Logic:
Suppose S[i] == T[j], where i > 0 and j < |T| - 1. Then

    S[0..i] + T[j+1..]

has two valid splits: S[0..i-1] + T[j..] and
S[0..i] + T[j+1..]. Both parts in both splits are non-empty, so this
is an interesting abbreviation.

Conversely, take any interesting abbreviation and two of its split
points. At the first position where one split still uses T while the
other already uses S, the corresponding characters of S and T must
match. Therefore, every valid answer can be represented by a pair
(i, j) of the form above.

The resulting length is (i + 1) + (|T| - j - 1) = i + |T| - j.
For each letter, this is minimized by using its earliest occurrence in
S after index 0 and its latest occurrence in T before the final index.

Time:  O(|S| + |T|)
Space: O(1) auxiliary space (only 26 stored positions)
*/

#include <array>
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    array<int, 26> last;
    last.fill(-1);
    for (int j = 0; j < m - 1; ++j) {
        last[t[j] - 'a'] = j;
    }
    int best_i = -1;
    int best_j = -1;
    int best_length = n + m + 1;
    for (int i = 1; i < n; ++i) {
        const int j = last[s[i] - 'a'];
        const int length = i + m - j;
        if (j != -1 && length < best_length) {
            best_length = length;
            best_i = i;
            best_j = j;
        }
    }
    if (best_i == -1) { cout << -1 << '\n';
    } else { cout << s.substr(0, best_i + 1) << t.substr(best_j + 1) << '\n'; }

    return 0;
}
