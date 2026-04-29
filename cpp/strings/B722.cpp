#include <iostream>
#include <vector>
#include <string>
int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int N; std::cin >> N;

    auto vowel = [&](char c) -> bool {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y'); 
    };
    
    std::vector<int> a(N); for (int i = 0; i < N; i++) { std::cin >> a[i]; }
    std::string s;
    getline(std::cin, s);
    bool good = true;
    for (int i = 0; i < N; i++) {
        std::getline(std::cin, s);
        for (char c : s) {
            if (vowel(c)) {
                a[i]--;
            }
        }
        if (a[i] != 0) {
            good = false;
        }

    }
    std::cout << (good ? "YES" : "NO") << '\n';
    return 0;
}