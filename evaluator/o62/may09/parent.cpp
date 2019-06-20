#include <bits/stdc++.h>
#define iii tuple<int, int, int>
using namespace std;

const int N = 1e5+5;

vector<iii> que;
vector<int> g[N];
int n, m;
int par[N][18], dep[N];

void dfs(int u, int p) {
    dep[u] = dep[p] + 1, par[u][0] = p;
    for(int i = 1; i <= 17; ++i) par[u][i] = par[par[u][i-1]][i-1];
    for(int v : g[u]) if(v != p) dfs(v, u);
}

int lca(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    for(int i = 17; ~i; --i) if(dep[par[u][i]] >= dep[v]) u = par[u][i];
    if(u == v) return u;
    for(int i = 17; ~i; --i) if(par[u][i] != par[v][i]) u = par[u][i], v = par[v][i];
    return par[u][0];
}

int dsu[N], rot[N];

int find(int u) { return dsu[u] = dsu[u] == u ? u : find(dsu[u]); }
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
    for(int i = 1; i <= n; ++i) dsu[i] = rot[i] = i;
    for(int i = 0, t, u, v; i < m; ++i) {
        scanf("%d %d", &t, &u);
        if(t != 2) scanf("%d", &v);
        if(t == 1) g[u].emplace_back(v), g[v].emplace_back(u);
        que.emplace_back(t, u, v);
    }
    for(int i = 1; i <= n; ++i) if(dep[i] == 0) dfs(i, 0);
    for(auto zzz : que) {
        int t, u, v; tie(t, u, v) = zzz;
        if(t == 1) {
            u = find(u), v = find(v);
            dsu[u] = v;
        } else if(t == 2) {
            rot[find(u)] = u;
        } else {
            if(dep[u] < dep[v]) swap(u, v);
            int z = rot[find(u)];
            if(lca(u, z) == u) printf("%d\n", u);
            else printf("%d\n", v);
        }
    }
}