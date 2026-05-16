#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n), b(n); for (int i = 0; i < n; ++i) cin>>a[i]; 
        for (int i=0; i<n; ++i) cin>>b[i];
        vector<int> v(n); for (int i = 0; i < n; ++i) {v[i]=a[i]-b[i];}
        vector<int> ans;
        int mx = *max_element(v.begin(), v.end());
        for (int i = 0; i < n; ++i) {
            if (v[i]==mx) ans.push_back(i+1);
        }
        cout<<(int)ans.size()<<'\n';
        for (int x : ans) {
            cout<<x<<' ';
        }
        cout<<'\n';
    }
    return 0;
}