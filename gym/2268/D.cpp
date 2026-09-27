#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 5;
int n, p[MAXN], R[MAXN], L[MAXN];
ll dp[MAXN];
vector<int> unmarkAt[MAXN];
bool marked[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++){ cin >> p[i]; unmarkAt[i].clear(); marked[i] = false; }

        vector<int> st;
        for(int i = 1; i <= n; i++){
            while(!st.empty() && p[st.back()] < p[i]){ R[st.back()] = i; st.pop_back(); }
            st.push_back(i);
        }
        while(!st.empty()){ R[st.back()] = n + 1; st.pop_back(); }

        fill(L + 1, L + n + 1, n + 1);
        for(int i = n; i >= 1; i--)
            if(R[i] <= n) L[R[i]] = i;

        ll ans = 0;
        for(int l = 1, r = 1; r <= n; r++){
            if(R[r] <= n) continue;
            dp[r] = r - l;
            int lst = r, cnt = 0;                 
            if(L[r] <= n){ unmarkAt[L[r]].push_back(r); marked[r] = true; cnt++; }
            for(int i = r - 1; i >= l; i--){
                while(!marked[lst]) lst--;    
                if(lst == R[i]){
                    dp[i] = dp[R[i]] + (r - i - 1);
                } else {
                    int RR = (R[i] <= n ? R[R[i]] : n + 1);
                    int c2 = (R[i] - i - 1) + (RR <= n) + cnt - 1
                           - (RR <= n && L[RR] <= i ? 1 : 0);
                    dp[i] = dp[lst] + 2LL * (r - i) - 2 - c2;
                }
                for(int j : unmarkAt[i]){ marked[j] = false; cnt--; }
                if(L[i] <= n){ unmarkAt[L[i]].push_back(i); marked[i] = true; cnt++; }
            }
            for(int i = l; i <= r; i++) ans += dp[i] + (l - 1);
            l = r + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}