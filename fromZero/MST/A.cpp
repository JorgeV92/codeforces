#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <numeric>
#include <tuple>
using namespace std;

int n;
vector<vector<long long>> d;
vector<vector<pair<int,long long>>> adj;
vector<long long> dist;

void dfs(int u, int parent){
    for(auto& [v,w] : adj[u]){
        if(v == parent) continue;
        dist[v] = dist[u] + w;
        dfs(v, u);
    }
}

int main(){
    scanf("%d", &n);
    d.assign(n, vector<long long>(n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%lld", &d[i][j]);

    for(int i=0;i<n;i++){
        if(d[i][i]!=0){ printf("NO\n"); return 0; }
        for(int j=i+1;j<n;j++)
            if(d[i][j]!=d[j][i] || d[i][j]<=0){ printf("NO\n"); return 0; }
    }

    adj.assign(n, {});
    vector<long long> minw(n);
    vector<int> par(n, -1);
    vector<char> used(n, 0);
    used[0] = 1; minw[0] = 0;
    for(int j=1;j<n;j++){ minw[j] = d[0][j]; par[j] = 0; }
    for(int it=1; it<n; it++){
        int v = -1;
        for(int j=0;j<n;j++)
            if(!used[j] && (v==-1 || minw[j] < minw[v])) v = j;
        used[v] = 1;
        adj[v].push_back({par[v], minw[v]});
        adj[par[v]].push_back({v, minw[v]});
        for(int u=0;u<n;u++)
            if(!used[u] && d[v][u] < minw[u]){
                minw[u] = d[v][u];
                par[u] = v;
            }
    }

    for(int s=0;s<n;s++){
        dist.assign(n, -1);
        dist[s] = 0;
        dfs(s, -1);
        for(int i=0;i<n;i++)
            if(dist[i] != d[s][i]){ printf("NO\n"); return 0; }
    }
    printf("YES\n");
    return 0;
}