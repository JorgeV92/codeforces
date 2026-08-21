#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <unordered_set>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s, t; cin>>s>>t;
    int k; cin>>k;
    int n = s.size();
    vector<int64_t> pref(n+1);
    for (int i = 0; i < n; ++i) 
        pref[i+1] = pref[i] + (t[s[i]-'a'] == '0');
    
    const int p = 31;
    const int m = 1e9+9;
    vector<int64_t> p_pow(n+1);
    p_pow[0] = 1;
    for (int i = 1; i <= n; ++i) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<int64_t> h(n+1);
    for (int i = 0; i < n; ++i)
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
        
    int cnt = 0;
    for (int l = 1; l <= n; ++l) {
        unordered_set<int64_t> hs;
        for (int i = 0; i+l <= n; ++i) {
            int64_t bad = pref[i+l] - pref[i];
            if (bad > k) continue;
            int64_t cur_h = (h[i+l] + m - h[i]) % m;
            cur_h = (cur_h * p_pow[n-i-1]) % m;
             hs.insert(cur_h);
        }
        cnt += hs.size();
    }
    cout<<cnt<<'\n';

    return 0;
}