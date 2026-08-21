#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s;
    int n = s.size();
    int good = false;
    size_t AB = s.find("AB");
    if (AB != string::npos) {
        size_t BA = s.find("BA", AB+2);
        if (BA != string::npos) {
            good = true;
        }
    }

    size_t _BA = s.find("BA");
    if (_BA != string::npos) {
        size_t _AB = s.find("AB", _BA+2);
        if (_AB != string::npos) {
            good = true;
        }
    } 
    cout << (good ? "YES" : "NO") << '\n';
    return 0;
}