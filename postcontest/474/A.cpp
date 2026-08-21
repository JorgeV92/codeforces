#include <iostream>
#include <vector>
#include <string>
std::vector<std::string> keyboard{
  "  qwertyuiop",
  "asdfghjkl;",
  "zxcvbnm,./"
};
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  char shift{}; std:: cin >> shift;
  std::string M; std::cin >> M;
  for (char c : M) {
    for (const auto& row : keyboard) {
      std::size_t idx = row.find(c);
      if (idx == std::string::npos) continue;
      int loc = idx + (shift == 'R' ? -1 : 1);
      std::cout << row[loc];
    }
  }
  std::cout << '\n';
  return 0;
}
