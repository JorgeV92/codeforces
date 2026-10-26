#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int n, m; std::cin >> n >> m;
        std::string s, t; std::cin >> s >> t;
        auto build = [&](const std::string &str, int maxD) {
            std::vector<int> writes, gaps, result(maxD + 1);
            for (int i = 0; i < (int) str.size(); i++) {
                if (str[i] == 'W') writes.push_back(i + 1);
            }
            for (int i = 1; i < (int) writes.size(); i++) gaps.push_back(writes[i] - writes[i - 1]);
            std::sort(gaps.begin(), gaps.end());
            int groups = writes.size(), at = 0, span = 0;
            for (int d = 1; d <= maxD; d++) {
                while (at < (int) gaps.size() && gaps[at] <= d) {
                    groups--;
                    span += gaps[at];
                    at++;
                }
                result[d] = groups * d + span;
            }
            return result;
        };
        std::vector<int> fromS = build(s, m), fromT = build(t, n);
        auto answer = [&](const std::string &str, const std::string &other, const std::vector<int> &values) {
            std::vector<int> result;
            int lastWrite = 0, otherLastWrite = 0;
            for (int i = 0; i < (int) other.size(); i++) {
                if (other[i] == 'W') otherLastWrite = i + 1;
            }
            for (int i = 0; i < (int) str.size(); i++) {
                if (str[i] == 'W') {
                    lastWrite = i + 1;
                    continue;
                }
                int d = i + 1 - lastWrite;
                if (lastWrite == 0) result.push_back(values[d] + 1);
                else if (otherLastWrite == 0) result.push_back(other.size() + 1);
                else result.push_back(std::max((int) other.size() + 1, otherLastWrite + d));
            }
            return result;
        };
        std::vector<int> a = answer(s, t, fromT), b = answer(t, s, fromS);
        for (int i = 0; i < (int) a.size(); i++) std::cout << (i ? " " : "") << a[i];
        std::cout << '\n';
        for (int i = 0; i < (int) b.size(); i++) std::cout << (i ? " " : "") << b[i];
        std::cout << '\n';
    }
    return 0;
}
