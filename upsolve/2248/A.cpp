#include <iostream>
#include <regex>
#include <vector>
#include <string>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) { 
    std::string s; std::cin >> s; 
    s.erase(s.find('0'), 1);
    s.erase(s.find('1'), 1);
    std::cout << s << '\n';
  }
  return 0;
}
