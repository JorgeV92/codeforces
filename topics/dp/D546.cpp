#include <iostream>
#include <vector>
using namespace std;
const int maxn=5e6;
vector<int> spf(maxn+1);
vector<int> o(maxn+1);
vector<int> pref(maxn+1);
auto sieve() -> void {
    for (int i=0;i<=maxn;i++) {
        spf[i]=i;
    }
    spf[0]=0;
    spf[1]=1;
    for (int i=2;i*i<=maxn;i++) {
        if (spf[i]==i) {
            for (int j=i*i;j<=maxn;j+=i) {
                if (spf[j]==j) {
                    spf[j]=i;
                }
            }
        }
    }
    o[1]=0;
    pref[1]=0;
    for (int i=2;i<=maxn;i++) {
        o[i]=o[i/spf[i]]+1;
        pref[i]=pref[i-1]+o[i];
    }
}
int main() {
    int T; cin>>T;
    sieve();
    while (T--) {
        int a,b; cin>>a>>b; 
        cout<<pref[a]-pref[b]<<'\n';
    }
    return 0;
}