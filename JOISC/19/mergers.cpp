/*
Our solution is as follows. For each color c, we merge nodes that are in the path from two nodes ui and uj which are
of that color. This can be done using a DSU, and merging just the nodes in the path from u_i to u_i+1. Note that after 
we complete the merging process for all colors, we obtain a simplified version of the problem: that each node in the merged tree
represents one color. This is solved easily: ceil((# of leaves + 1)/2).
*/
#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 5e5+5;

int n, k;
vector<int> g[N];
vector<pii> E;
int dep[N], dsu[N], deg[N], par[N];
vector<int> col[N];

int find(int u) { return dsu[u] = dsu[u] == u ? u : find(dsu[u]); }

void init_dep(int u, int p) {
    dep[u] = dep[p] + 1, par[u] = p;
    for(int v : g[u]) if(v != p) init_dep(v, u);
}

int main() {
    iota(dsu, dsu+N, 0);
    scanf("%d %d", &n, &k);
    for(int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        g[u].emplace_back(v), g[v].emplace_back(u);
        E.emplace_back(u, v);
    }
    for(int i = 1, v; i <= n; ++i) {
        scanf("%d", &v);
        col[v].emplace_back(i);
    }
    init_dep(1, 0);
    for(int i = 1; i <= k; ++i) if(col[i].size() > 1) {
        for(int j = 1; j < col[i].size(); ++j) {
            int a = find(col[i][j-1]), b = find(col[i][j]);
            while(a != b) {
                if(dep[a] < dep[b]) swap(a, b);
                dsu[a] = find(par[a]);
                a = dsu[a];
            }
        } 
    }
    for(auto x : E) {
        int a = find(x.x), b = find(x.y);
        if(a != b) deg[a]++, deg[b]++;
    }
    int cnt = 0;
    for(int i = 1; i <= n; ++i) if(deg[i] == 1) cnt++;
    printf("%d\n", (cnt+1) / 2);
}
