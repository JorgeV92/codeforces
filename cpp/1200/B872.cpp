#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >>n>>k;
    vector<int> a(n); for (int& x : a) cin>>x;
    if (k==1) {
        cout<<*min_element(a.begin(),a.end())<<'\n';
    } else if (k==2) {
        cout<< max(a[0],a[n-1])<<'\n';
    } else {
        cout<<*max_element(a.begin(),a.end())<<'\n';
    }
    return 0;
}