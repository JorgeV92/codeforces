#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >>T;
    while (T--) {
        int n; cin>>n;
        string s; cin>>s;
        pair<string,int> ans{s,1};
        for (int k = 1; k <= n; ++k) {
            string suffix = s.substr(k-1);
            string prefix = s.substr(0,k-1);
            int m = n-k+1;
            if (m%2==1) 
                reverse(prefix.begin(), prefix.end());
            string t = suffix + prefix;
            ans = min(ans, make_pair(t, k));
        }
        cout<<ans.first<<'\n';
        cout<<ans.second<<'\n';
    }
    return 0;
}