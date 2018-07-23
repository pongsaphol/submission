#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1e5+5;

int n, m, ans[N], pos[N], sz[N], dep[N], par[N][17], in[N], out[N], freq[N];
vector<int> g[N];
vector<pii> q[N];

void get_sz(int u, int p) {
    static int idx = 0;
    in[u] = ++idx, pos[idx] = u, par[u][0] = p, dep[u] = dep[p]+1;
    for(int i = 1; i < 17; ++i) par[u][i] = par[par[u][i-1]][i-1];
    for(int &v : g[u]) {
        get_sz(v, u); 
        sz[u] += sz[v];
        if(sz[v] > sz[g[u][0]]) swap(v, g[u][0]);
    }
    out[u] = idx;
}

void sack(int u, bool st) {
    for(int v : g[u]) if(v != g[u][0]) sack(v, false);
    if(g[u].size()) sack(g[u][0], true);
    freq[dep[u]]++;
    for(int v : g[u]) if(v != g[u][0]) 
        for(int i = in[v]; i <= out[v]; ++i) freq[dep[pos[i]]]++;
    for(pii x : q[u]) ans[x.x] = freq[x.y]-1; 
    if(!st) for(int i = in[u]; i <= out[u]; ++i) freq[dep[pos[i]]]--;
}

int main() {
    scanf("%d", &n);
    for(int i = 1, p; i <= n; ++i) {
        scanf("%d", &p);
        g[p].emplace_back(i);
    }
    for(int v : g[0]) get_sz(v, 0);
    scanf("%d", &m);
    auto get = [&](int u, int p) {
        for(int i = 16; ~i; --i) if(p >> i & 1) u = par[u][i];
        return u;
    };
    for(int i = 0, v, p; i < m; ++i) {
        scanf("%d %d", &v, &p);
        if(dep[v] <= p) continue; 
        q[get(v, p)].emplace_back(i, dep[v]);
    }
    for(int v : g[0]) sack(v, false);
    for(int i = 0; i < m; ++i) printf("%d ", ans[i]);
}
