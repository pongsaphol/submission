#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;

int n, m;
int rot[N];
int par[N];
int srot[N];
vector<int> g[N];

int find(int u) { return par[u] = par[u] == u ? u : find(par[u]); }

void dfs(int u, int p, int col) {
    rot[u] = col;
    for(int v : g[u]) if(v != p) dfs(v, u, col);
}

int dfs2(int u, int p, int a, int b) {
    if(u == a) return u;
    if(u == b) return u;
    for(int v : g[u]) if(v != p) {
        int z = dfs2(v, u, a, b);
        if(z != -1) return z;
    }
    return -1;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) rot[i] = srot[i] = par[i] = i;
    for(int i = 0, t, u, v; i < m; ++i) {
        scanf("%d %d", &t, &u);
        if(t != 2) scanf("%d", &v);
        if(t == 1) {
            dfs(u, 0, rot[v]);
            g[u].emplace_back(v), g[v].emplace_back(u);
            u = find(u), v = find(v);
            par[u] = v;
        } else if(t == 2) {
            dfs(u, 0, u);
            srot[find(u)] = u;
        } else {
            assert(srot[find(u)] == rot[u]);
            assert(srot[find(v)] == rot[v]);
            printf("%d\n", dfs2(rot[u], 0, u, v)); 
        }
    }
}