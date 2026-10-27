#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n, m, q; std::cin >> n >> m >> q;
        std::vector<std::pair<int, int>> current(m);
        for (auto &[l, r] : current) {
            std::cin >> l >> r;
            l--;
        }
        std::vector<int> start(m, 0);
        std::vector<std::vector<std::pair<int, int>>> tree(4 * (q + 1));
        auto add = [&](auto &&self, int node, int left, int right,
                       int ql, int qr, std::pair<int, int> edge) -> void {
            if (qr <= left || right <= ql) return;
            if (ql <= left && right <= qr) {
                tree[node].push_back(edge);
                return;
            }
            int mid = (left + right) / 2;
            self(self, 2 * node, left, mid, ql, qr, edge);
            self(self, 2 * node + 1, mid, right, ql, qr, edge);
        };
        for (int time = 1; time <= q; time++) {
            int p, l, r; std::cin >> p >> l >> r;
            p--; l--;
            add(add, 1, 0, q + 1, start[p], time, current[p]);
            current[p] = {l, r};
            start[p] = time;
        }
        for (int i = 0; i < m; i++)
            add(add, 1, 0, q + 1, start[i], q + 1, current[i]);
        std::vector<int> parent(n + 1), size(n + 1, 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
        struct Change { int v, parent, size; };
        std::vector<Change> history;
        int answer = 0;
        auto find = [&](auto &&self, int v) -> int {
            return parent[v] == v ? v : self(self, parent[v]);
        };
        auto unite = [&](int a, int b) {
            a = find(find, a); b = find(find, b);
            if (a == b) return false;
            if (size[a] < size[b]) std::swap(a, b);
            history.push_back({a, parent[a], size[a]});
            history.push_back({b, parent[b], size[b]});
            parent[b] = a;
            size[a] += size[b];
            return true;
        };
        auto dfs = [&](auto &&self, int node, int left, int right) -> void {
            int oldAnswer = answer, oldSize = history.size();
            for (auto [a, b] : tree[node]) answer += unite(a, b);
            if (right - left == 1) std::cout << answer << '\n';
            else {
                int mid = (left + right) / 2;
                self(self, 2 * node, left, mid);
                self(self, 2 * node + 1, mid, right);
            }
            while ((int)history.size() > oldSize) {
                auto [v, oldParent, oldSize] = history.back();
                history.pop_back();
                parent[v] = oldParent;
                size[v] = oldSize;
            }
            answer = oldAnswer;
        };
        dfs(dfs, 1, 0, q + 1);
    }
    return 0;
}
