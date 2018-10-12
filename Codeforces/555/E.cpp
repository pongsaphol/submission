#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int n, m, q;
bool check[N];
vector<int> g[N];
int d[N], d1[N], d2[N];
int com[N];
int dep[N], par[N][18];

void dfs_tree(int u, int p, int c) {
    com[u] = c;
    check[u] ^= 1;
    for(int i = 1; i < 18; ++i) par[u][i] = par[par[u][i-1]][i-1];
    for(int v : g[u]) {
        if(check[v]) { if(dep[v] < dep[u]) d[u]++, d[v]--;}
        else dep[v] = dep[u] + 1, par[v][0] = u, g[v].erase(find(g[v].begin(), g[v].end(), u)), dfs_tree(v, u, c);
    } 
}

int get_lca(int a, int b) {
    if(dep[a] < dep[b]) swap(a, b);
    for(int i = 17; ~i; --i) if(dep[par[a][i]] >= dep[b]) a = par[a][i];
    if(a == b) return a;
    for(int i = 17; ~i; --i) if(par[a][i] != par[b][i]) a = par[a][i], b = par[b][i];
    return par[a][0];
}

bool answer;

void dfs_fill(int u, int p) {
    check[u] ^= 1;
    for(int v : g[u]) if(check[v]) {
        dfs_fill(v, u);
        d[u] += d[v], d1[u] += d1[v], d2[u] += d2[v];
    }
    if(!d[u] && d1[u] && d2[u]) answer = true;
}

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 0, u, v; i < m; ++i) {
        scanf("%d %d", &u, &v);
        g[u].emplace_back(v), g[v].emplace_back(u);
    }
    int idx = 0;
    for(int i = 1; i <= n; ++i) if(!check[i])
        dep[i] = 1, dfs_tree(i, 0, ++idx);
    for(int i = 0, u, v; i < q; ++i) {
        scanf("%d %d", &u, &v);
        if(com[u] != com[v]) return puts("No"), 0;
        int lca = get_lca(u, v);
        d1[u]++, d1[lca]--, d2[v]++, d2[lca]--;
    }
    dfs_fill(1, 0);
    printf(answer ? "No" : "Yes");
}
