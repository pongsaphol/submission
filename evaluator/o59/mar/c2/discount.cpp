#include <bits/stdc++.h>
using namespace std;

#define iii tuple<int, int, int>
#define pii pair<int, int>
#define x first
#define y second

const int N = 2e4+5;

int n, m;
int P[N], dep[N];
pii par[N][15];

vector<pii> g[N];

int find(int u) { return P[u] = P[u] == u ? u : find(P[u]); }

void init_lca(int u, int p) {
    for(int i = 1; i < 15; ++i) par[u][i] = pii(par[par[u][i-1].x][i-1].x, max(par[u][i-1].y, par[par[u][i-1].x][u-1].y));
    for(pii v : g[u]) if(v.x != p) dep[v.x] = dep[u] + 1, par[v.x][0] = pii(u, v.y), init_lca(v.x, u);
}

pii get_lca(int a, int b) {
    if(dep[a] < dep[b]) swap(a, b);
    int max_e = 0;
    for(int i = 14; ~i; --i) if(dep[par[a][i].x] >= dep[b]) max_e = max(max_e, par[a][i].y), a = par[a][i].x;
    if(a == b) return pii(a, max_e);
    for(int i = 14; ~i; --i) if(par[a][i].x != par[b][i].x) max_e = max({max_e, par[a][i].y, par[b][i].y}), a = par[a][i].x, b = par[b][i].x;
    return pii(par[a][0].x, max({max_e, par[a][0].y, par[b][0].y}));
}

int main() {
    iota(P, P+N, 0);
    scanf("%d %d", &n, &m);
    vector<iii> V;
    for(int i = 0, a, b, c; i < m; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        a++, b++;
        V.emplace_back(a, b, c);
    }
    sort(V.begin(), V.end(), [&](const iii &a, const iii &b) { return get<2>(a) < get<2>(b); });
    vector<iii> ret;
    for(auto x : V) {
        int u, v, w; tie(u, v, w) = x;
        u = find(u), v = find(v);
        if(u != v) P[u] = v, g[u].emplace_back(v, w), g[v].emplace_back(u, w);
        else ret.emplace_back(x);
    }
    init_lca(1, 0);
    int min_e = 1e9;
    for(auto x : ret) {
        int u, v, w; tie(u, v, w) = x;
        pii now = get_lca(u, v);
        assert(w > now.y);
        min_e = min(min_e, w - now.y);
    }
    printf("%d\n", min_e+1);
}
