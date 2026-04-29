#include <iostream>
#include <vector>
#include <string>
int main() {    
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int N; std::cin >> N;
    std::vector<std::string> pat(N); for (int i = 0; i < N; i++) { std::cin >> pat[i]; }
    int M = pat[0].size();
    std::string res{};
    for (int j = 0; j < M; j++) {
        bool conflict =  false; 
        char t = '?';
        for (int i = 0; i < N; i++) {
            if (pat[i][j] == '?') continue;
            if (t == '?') t = pat[i][j];
            else if (t != pat[i][j]) conflict = true;
        }
        if (conflict) {
            res += '?';
        } else if (t == '?') {
            res += 'x';
        } else {
            res += t;
        }
    }
    std::cout << res << '\n';
    return 0;   
}