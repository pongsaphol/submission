#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

int n, m;
int dep[N], par[N][20];
int d[2][N];
int sz[N];
bool markl[N];
vector<int> g[N];

void dfs(int u, int p) {
    par[u][0] = p;
    for(int i = 1; i < 20; ++i) par[u][i] = par[par[u][i-1]][i-1];
    for(int v : g[u]) dfs(v, u), sz[u] += sz[v];
}

int solve(int u) {
    int mx = 0, mx2 = 0;
    int from;
    for(auto v : g[u]) {
        sz[u] += sz[v];
        solve(v);
        if(mx < d[0][v]) {
            mx = d[0][v];
            from = v;
        }
        mx = max(mx, d[0][v]);
        mx2 = max(mx2, d[1][v]);
    }
    for(auto v : g[u]) if(v != from) {
        if(!sz[v]) mx2 = max(mx2, mx + 1);
    }
    d[0][u] += mx, d[1][u] += mx2;
}

int main() {
    scanf("%d %d", &n, &m);
    markl[1] = true;
    for(int i = 2; i <= n; ++i) {
        int p; scanf("%d", &p);
        g[p].emplace_back(i);
        markl[p] = true;
    }
    dfs(1, 0);
    for(int i = 1; i <= n; ++i) if(!markl[i]) {
        int a = i;
        sz[a]++;
        for(int i = 0; i < 20; ++i) if(m >> i & 1) a = par[a][i]; 
        if(a == 0) a = 1;
        sz[a]--;
        d[0][a]++, d[1][a]++;
    }
    solve(1);
    printf("%d\n", max(d[0][1], d[1][1])); 
}
