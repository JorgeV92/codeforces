#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;
int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    string s{}; std::cin >> s;
    int N; std::cin >> N;
    vector<string> strs(N); for (int i = 0; i < N; i++) { std::cin >> strs[i]; }
    auto norm = [&](char c) -> char {
        c = towlower(c);
        if (c == 'o' || c == '0') return '0';
        if (c == 'i' || c == 'l' || c == '1') return '1';
        return c;
    };
    auto normalize = [&](const string& s) {
        string res = s;
        for (char& c : res) {
            c = norm(c);
        }
        return res;
    };
    string t = normalize(s);
    for (int i = 0; i < N; i++) {
        string cur = strs[i];
        if (normalize(cur) == t) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}