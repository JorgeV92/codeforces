#include <iostream>
#include <vector>
#include <string>
#include <functional>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s;
    int n = s.size();
    vector<string> ss;
    vector<int> cnt(26);
    for (char c : s) { cnt[c-'a']++; }


    function<void(string&)> search = [&](string& t) {
        if (t.size() == s.size()) {
            ss.push_back(t);
            return;
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > 0) {
                cnt[i]--;
                t += (char)('a' + i);
                search(t);
                t.pop_back();
                cnt[i]++;
            }
        }

    }; 
    string t{};
    search(t);

    cout << ss.size() << '\n';
    for (const string& p : ss) { cout << s << '\n'; }
    return 0;
}