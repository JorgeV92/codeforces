#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> cnt(26);
        for (char c : s) cnt[c-'a']++;
        vector<int> ord(26);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j) {
            return cnt[i] > cnt[j];
        });
        int best_k = 1;
        int best_keep = 0;
        for (int k = 1; k <= 26; k++) {
            if (n % k == 0) {
                int t = n/k;
                int keep = 0;
                for (int i = 0; i < k; i++) {
                    keep += min(cnt[ord[i]], t);
                }
                if (keep > best_keep) {
                    best_keep = keep;
                    best_k = k;
                }
            }
        }
        int t = n / best_k;
        vector<int> tcnt(26);
        for (int i = 0; i < best_k; i++) {
            tcnt[ord[i]] = t;
        }
        vector<int> used(26);
        vector<int> replace;
        string ans = s;
        for (int i = 0; i < n; ++i) {
            int c = s[i]-'a';
            if (used[c] < tcnt[c]) used[c]++;
            else replace.push_back(i);
        }
        vector<char> need;
        for (int c = 0; c < 26; c++) {
            while (used[c] < tcnt[c]) {
                need.push_back('a'+c);
                used[c]++;
            }
        }
        for (int i = 0; i < (int)replace.size(); ++i) {
            ans[replace[i]] = need[i];
        }
        cout << n - best_keep << '\n';
        cout << ans << '\n';
    }
    return 0;
}