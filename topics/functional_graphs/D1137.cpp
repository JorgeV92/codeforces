#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    while (true) {
        cout << "next " << 0 << ' ' << 1 << '\n' << flush;
        int k; cin >> k; for (int i = 0; i < k; i++) { string s{}; cin>>s; }
        cout << "next " << 0 << '\n' << flush;
        cin >> k; for (int i = 0; i < k; i++) {string s{}; cin>>s; }
        if (k == 2) {
            break;
        }
    }
    while (true) {
        cout << "next "; for (int x = 0; x < 10; x++) { cout << x << " "; } cout << '\n' << flush; 
        int k; cin >> k; for (int i = 0 ; i < k; i++) {string s{}; cin >> s; }
        if (k == 1) {
            cout << "done\n" << flush;
            exit(0);
        }
    }
    return 0;
}