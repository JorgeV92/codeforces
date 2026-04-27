#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin>>n; bool good = false; 
        for (int i =0; i<n; i++) {
            int a; cin>>a;
            if (a==100) good = true;
        }
        cout << (good ? "Yes" : "No") << '\n';
    }
    return 0;   
}