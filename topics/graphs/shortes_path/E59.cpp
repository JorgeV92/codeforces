#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#define mp(a,b) std::make_pair(a,b)
using pii = std::pair<int,int>;
using vii = std::vector<pii>;
std::vector<int> adj[3005];
int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int N, M, K; std::cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) 
        adj[i].clear();
    for (int i = 0; i < M; i++) {
        int a, b; std::cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    std::map<pii, std::set<int>> nogo;
    for (int i = 0; i < K; i++) {
        int a, b, c; std::cin >> a >> b >> c;
        nogo[mp(a,b)].insert(c);
    }
    std::set<int> empty_set;
    std::queue<pii> q;
    std::map<pii, pii> prv;
    q.push(mp(1, 0));
    prv.insert(mp(mp(1, 0), mp(0,0)));
    while (!q.empty()) {
        int v = q.front().first;
        int p = q.front().second;
        q.pop();
        if (v == N) {
            std::vector<int> path;
            for (auto t = mp(v, p); t.first != 1; t = prv[t]) {
                path.push_back(t.first);
            }
            std::reverse(path.begin(), path.end());
            std::cout << (int)path.size() << "\n1 ";
            for (int i = 0; i < (int)path.size(); i++) {
                std::cout << path[i] << " ";
            }
            std::cout << '\n';
            goto end;
        }
        std::set<int>* se;
        if (!nogo.count(mp(p, v))) 
            se = &empty_set;
        else
            se = &nogo[mp(p, v)];
        for (int u : adj[v]) {
            if (se->count(u)) continue;
            int nxt = u;
            int tp = nogo.count(mp(v, u)) == 0 ? 0 : v;
            if (prv.count(mp(nxt, tp))) continue;
            prv.insert(mp(mp(nxt, tp), mp(v, p)));
            q.push(mp(nxt, tp));
        }
    }
    std::cout << "-1\n"; 
    end:;
    return 0;
}