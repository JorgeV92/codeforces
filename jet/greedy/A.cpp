#include <iostream>
#include <vector>
#include <string>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  std::string s; std::cin>>s;
  int n = s.size();
  std::vector<int> st; 
  std::vector<char> k(n,0);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') st.push_back(i);
    else if (!st.empty()) {
      k[st.back()] = 1;
      k[i] = 1;
      st.pop_back();
    }
  }
  std::string ans{};
  for (int i = 0; i < n; ++i) {
    if (k[i]) ans+=s[i];
  }
  std::cout << ans.size() << '\n';
  std::cout << ans << '\n';
  return 0;
}
