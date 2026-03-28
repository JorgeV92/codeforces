#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> z_funciton(std::string s) {
    int n = s.length();
    std::vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            int k = i-l;
            z[i] = std::min(r - i, z[k]);
        }
        // “While the next character exists, and the next character 
        // of the prefix matches the next character of the substring starting at i, 
        // keep extending the match.”
        while (i + z[i] < n && s[z[i]] == s[i+z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

std::vector<int> search(std::string& text, std::string& pattern) {
    std::string s = pattern + '$' + text;
    std::vector<int> z = z_funciton(s);
    std::vector<int> p;
    int m = pattern.size();
    for (int i = m + 1; i < z.size(); i++) {
        if (z[i] == m) {
            p.push_back(i - m - 1);
        }
    }
    return p;
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // std::string s;
    // std::cin >> s;
    // std::vector<int> z = z_funciton(s);
    // for (auto x : z) std::cout << x << ' ';
    // std::cout << '\n'; 

    std::string text, pattern;
    std::cin >> text >> pattern;
    std::vector<int> mathces = search(text, pattern);
    for (auto x : mathces) std::cout << x << " ";
    std::cout << '\n';
    return 0;
}