#include <iostream>
#include <vector>

int string_match(const std::string& s, const std::string& t) {
  int n = s.size();
  int m = t.size();

  for (int i = 0; i + m - 1 < n; ++i) {
    bool found = true;
    for (int j = 0; j < m; ++j) {
      if (s[i+j] != t[j]) {
        found = false;
        break;
      }
    }
    if (found) return i;
  }
  return -1;
}



int main() {

  return 0;
}

