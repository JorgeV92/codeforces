#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<string> strs; string s;
    int width = 0;
    while (getline(cin, s)) {
        strs.push_back(s);
        width = max(width, (int)s.size());
    }
    cout << string(width+2, '*') << '\n';
    bool left = true;
    for (auto& t : strs) {
        int len = t.size();
        int spaces = width - len;
        int l = spaces / 2;
        int r = spaces - l;
        if (spaces % 2 == 1) {
            if (left) {
                l = spaces / 2;
                r = spaces - l;
            } else {
                r = spaces / 2;
                l = spaces - r;
            }
            left = !left;
        }
        cout << '*';
        cout << string(l, ' ');
        cout << t;
        cout << string(r, ' ');
        cout << '*' << '\n';
    }
    cout << string(width+2, '*') << '\n';
    return 0;
}