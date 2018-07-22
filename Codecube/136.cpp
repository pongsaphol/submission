#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

int n, m;

int solve() {
    scanf("%d %d", &n, &m);
    vector<vector<int> > g(n+1);
    set<pii> S;
    for(int i = 1; i <= n; ++i) for(int j = i+1; j <= n; ++j) S.emplace(i, j);
    for(int i = 0, u, v; i < m; ++i) {
        scanf("%d %d", &u, &v); if(u > v) swap(u, v);
        S.erase(pii(u, v));
    }
    for(auto x : S) {
        g[x.x].emplace_back(x.y);
        g[x.y].emplace_back(x.x);
    }
    vector<int> ret, status(n+1, 0);
    for(int i = 1; i <= n; ++i) if(!status[i]){
        int cnt = 0;
        queue<int> Q; Q.emplace(i); status[Q.front()] = 1;
        while(!Q.empty()) {
            cnt += status[Q.front()] == 1;
            for(auto v : g[Q.front()]) {
                if(status[v]) { if(status[v] == status[Q.front()]) return -1; } 
                else status[v] = status[Q.front()] == 1 ? 2 : 1, Q.emplace(v);                
            }  
            Q.pop();
        }
        ret.emplace_back(cnt);
    }
    bitset<1000> knapsack;
    knapsack[0] = true;
    int mn = 1e9;
    for(auto x : ret) 
        for(int i = n - x; ~i; --i) if(knapsack[i]) knapsack[i+x] = true;
    for(int i = 0; i <= n; ++i) if(knapsack[i]) mn = min(mn, abs(n-i-i));
    return mn;
}

int main() {
    int T; scanf("%d", &T);
    while(T--) printf("%d\n", solve());
}
