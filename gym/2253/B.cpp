#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n;
        std::vector<int> a(n); 
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        std::vector<std::pair<int,int>> runs;
        for (int x : a) {
            if (runs.empty() || runs.back().first != x) {
                runs.emplace_back(x, 1);
            } else {
                runs.back().second++;
            }
        }
        int m = runs.size();
        bool add_two = false;
        for (int i = 0; i + 1 < m; i++) {
            if (runs[i].second > 1 && runs[i+1].second > 1) {
                add_two = true;
                break;
            }
        }
        if (add_two) {
            std::cout << m + 2 << '\n';
            continue;
        }
        bool add_one = false;
        for (int i = 0; i < m; ++i) {
            if (runs[i].second <= 1) continue;
            bool r = (i+1 < m && (i+2 >= m || runs[i+2].first != runs[i].first));
            bool l = (i > 0 && (i-2 < 0 || runs[i-2].first != runs[i].first));
            if (r || l) {
                add_one = true;
                break;
            }
        }
        if (add_one) {
            std::cout << m + 1 << '\n';
            continue;
        }
        std::cout << m << '\n';
    }
    return 0;
}