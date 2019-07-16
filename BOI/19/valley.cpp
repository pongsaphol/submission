#include <bits/stdc++.h>
#define long long long
#define pii pair<long, long>
#define x first
#define y second
using namespace std;

const long INF = 1e18;
const int N = 1e5+5;

int n, m, q, st;
int s[N], t[N], w[N];
int par[N][17], dep[N], id[N], rid[N];
long dist[N], cost[N], mnq[N][17];
vector<int> g[N];

void init_lca(int u, int p) {
    dep[u] = dep[p] + 1, par[u][0] = p;
    for(int i = 1; i < 17; ++i) par[u][i] = par[par[u][i-1]][i-1];
    for(int x : g[u]) {
        int v = s[x] ^ t[x] ^ u;
        if(v == p) continue;
        dist[v] = dist[u] + w[x];
        id[x] = v, rid[v] = x;
        init_lca(v, u);
    }
}

int get_lca(int a, int b) {
    if(dep[a] < dep[b]) swap(a, b);
    for(int i = 16; ~i; --i) if(dep[par[a][i]] >= dep[b]) a = par[a][i];
    if(dep[a] == dep[b]) return a;
    for(int i = 16; ~i; --i) if(par[a][i] != par[b][i]) a = par[a][i], b = par[b][i];
    return par[a][0];
}

int main() {
    scanf("%d %d %d %d", &n, &m, &q, &st);
    for(int i = 1; i < n; ++i) {
        scanf("%d %d %d", s+i, t+i, w+i);
        g[s[i]].emplace_back(i), g[t[i]].emplace_back(i);
    }
    init_lca(st, 0);
    fill_n(cost, N, INF);
    priority_queue<pii, vector<pii>, greater<pii> > Q;
    for(int i = 0, val; i < m; ++i) {
        scanf("%d", &val);
        Q.emplace(cost[val] = 0, val);
    }
    while(!Q.empty()) {
        auto uu = Q.top(); Q.pop();
        if(uu.x != cost[uu.y]) continue;
        int u = uu.y, v = par[uu.y][0], ww = w[rid[uu.y]];
        if(cost[v] > cost[u] + ww) Q.emplace(cost[v] = cost[u] + ww, v);
    }
    for(int j = 0; j < 17; ++j) {
        for(int i = 1; i <= n; ++i) {
            if(j) mnq[i][j] = min(mnq[i][j-1], mnq[par[i][j-1]][j-1]);
            else mnq[i][j] = cost[i] - (cost[i] == INF ? 0 : dist[i]);
        }
    }
    for(int i = 0, a, b; i < q; ++i) {
        scanf("%d %d", &a, &b);
        int v = id[a];
        if(get_lca(b, v) != v) {
            puts("escaped");
            continue;
        } 
        long mn = INF;
        int bb = b;
        for(int i = 16; ~i; --i) if(dep[par[b][i]] >= dep[v]-1) {
            mn = min(mn, mnq[b][i]);
            b = par[b][i];
        }
        if(mn == INF) puts("oo");
        else printf("%lld\n", mn + dist[bb]);
    }

}