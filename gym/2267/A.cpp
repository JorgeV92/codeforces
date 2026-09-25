#include <iostream>
#include <vector>
#include <string>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int t; std::cin >> t;
    while (t--) {
        int n; std::cin >> n;
        char c; std::cin >> c;
        std::string s; std::cin >> s;
        int cnt =0 ;
        for (int i = 0; i *2 < n; i++) {
            if (s[i] != s[n-i-1]) {
                if (s[i] !=  c) cnt++;
                if (s[n-i-1] != c) cnt++;
            } 
        }
        std::cout << cnt << '\n';
    }
    return 0;
}