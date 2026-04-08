#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

#ifdef ONLINE_JUDGE
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
#else
    #define fin std::cin
    #define fout std::cout
#endif

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, X; fin >> n >> X;
    vector<int>c(n);
    for (int i=0;i<n;i++) {
        fin>>c[i];
        c[i]*=(n-i);
    }
    sort(c.begin(),c.end());
    int sum=0;
    int t=0;
    for (int x:c) {
        if (sum+x<=X) {
            t++;
            sum+=x;
        } else {
            break;
        }
    }
    fout<<t<<'\n';
    return 0;
}
