#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define x first
#define y second

const int N = 3e5+5;
const int M = 1e9+7;

int n, m, dep[N], col[N], high[N], par[N][19];
vector<int> g[N];
vector<pii> E[N];

void init_lca(int u, int p) {
    dep[u] = dep[p]+1, par[u][0] = p;
    for(int i = 1; i < 19; ++i) par[u][i] = par[par[u][i-1]][i-1];
    for(int v : g[u]) if(v != p) init_lca(v, u);
}

int get_lca(int a, int b) {
    if(dep[a] < dep[b]) swap(a, b);
    for(int i = 18; ~i; --i) if(dep[par[a][i]] >= dep[b]) a = par[a][i];
    if(a == b) return a;
    for(int i = 18; ~i; --i) if(par[a][i] != par[b][i]) a = par[a][i], b = par[b][i];
    return par[a][0];
}

void build(int u, int p) {
    for(int v : g[u]) if(v != p) {
        build(v, u), high[u] = min(high[u], high[v]); 
        if(high[v] < dep[u]) 
            E[u].emplace_back(v, 0), E[v].emplace_back(u, 0);
    }
}

bool dfs(int u, int c) {
    if(col[u] != -1) return col[u] == c;
    col[u] = c;
    for(pii v : E[u]) if(!dfs(v.x, c ^ v.y)) return false;
    return true;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1, a, b; i < n; ++i) {
        scanf("%d %d", &a, &b);
        g[a].emplace_back(b), g[b].emplace_back(a);
    }
    init_lca(1, 0);
    for(int i = 1; i <= n; ++i) high[i] = dep[i];
    for(int i = 0, u, v; i < m; ++i) {
        scanf("%d %d", &u, &v);
        int lca = get_lca(u, v);
        high[u] = min(high[u], dep[lca]);
        high[v] = min(high[v], dep[lca]);
        if(u != lca && v != lca) 
            E[u].emplace_back(v, 1), E[v].emplace_back(u, 1);            
    }
    build(1, 0);
    int ans = 1; memset(col, -1, sizeof col);
    for(int i = 2; i <= n; ++i) if(col[i] == -1) {
        if(!dfs(i, 0)) return !printf("0");
        ans = ans * 2 % M; 
    }
    return !printf("%d\n", ans);
}