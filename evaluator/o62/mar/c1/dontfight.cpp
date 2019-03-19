#include <bits/stdc++.h>
#define long long long
using namespace std;

const long INF = 1e18;

const int N = 1<<19;

int n;
int in[N], out[N], pos[N], sz[N];
int inv[N];
long d[N];
vector<int> g[N];
vector<long> coor;
multiset<long> inc, exc;

int t[2][N], step[2][N];

void dfs_sz(int u, int p) {
    static int idx = 0;
    pos[in[u] = ++idx] = u, sz[u] = 1;
    if(p) g[u].erase(find(g[u].begin(), g[u].end(), p));
    for(int &v : g[u]) {
        dfs_sz(v, u);
        sz[u] += sz[v], d[u] += d[v];
        if(sz[v] > sz[g[u][0]]) swap(v, g[u][0]);
    }
    if(u != 1) coor.emplace_back(d[u]);
    out[u] = idx;
}

long ans = INF;

void track(long a, long b, long c) { ans = min(ans, max({a, b, c}) - min({a, b, c})); }

void upd(int t[], int x, int v) {
    for(int i = x; i <= n; i += i & -i) t[i] += v;
}

int que(int t[], int x, int v = 0) {
    for(int i = x; i; i -= i & -i) v += t[i];
    return v;
}

void ins(int z, long v) {
    v = inv[v];
    if(!step[z][v]) upd(t[z], v, 1);
    step[z][v]++;
}

void del(int z, long v) {
    v = inv[v];
    step[z][v]--;
    if(!step[z][v]) upd(t[z], v, -1);
}

long get(int k, long val, int zz) {
    int z = que(t[k], lower_bound(coor.begin(), coor.end(), val) - coor.begin()) + zz;
    if(z <= 0) return INF;
    int l = 1, r = n;
    while(l < r) {
        int m = l+r >> 1;
        if(que(t[k], m) >= z) r = m;
        else l = m+1;
    }
    if(r == n) return INF;
    return coor[r];
}

void dfs(int u, bool keep = true) {
    if(u != 1) del(1, u);
    for(int v : g[u]) if(v != g[u][0]) dfs(v, false);
    if(g[u].size()) dfs(g[u][0], true);
    if(u == 1) return;
    for(int v : g[u]) if(v != g[u][0]) for(int i = in[v]; i <= out[v]; ++i)
        ins(0, pos[i]), del(1, pos[i]);
    long z = get(0, d[u] >> 1, -1);
    track(d[1] - d[u], d[u] - z, z);
    z = get(0, d[u] >> 1, 0);
    track(d[1] - d[u], d[u] - z, z);
    z = get(0, d[u] >> 1, 1);
    track(d[1] - d[u], d[u] - z, z);
    z = get(1, d[1] - d[u] >> 1, -1);
    track(d[1] - d[u] - z, d[u], z);
    z = get(1, d[1] - d[u] >> 1, 0);
    track(d[1] - d[u] - z, d[u], z);
    z = get(1, d[1] - d[u] >> 1, 1);
    track(d[1] - d[u] - z, d[u], z);
    ins(0, u);
    inc.emplace(d[u]);
    if(!keep) for(int i = in[u]; i <= out[u]; ++i)
        ins(1, pos[i]), del(0, pos[i]);
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%lld", d+i);
    for(int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        g[u].emplace_back(v), g[v].emplace_back(u);
    }
    dfs_sz(1, 0);
    coor.emplace_back(-1);
    sort(coor.begin(), coor.end());
    coor.resize(unique(coor.begin(), coor.end()) - coor.begin());
    for(int i = 2; i <= n; ++i) {
        inv[i] = lower_bound(coor.begin(), coor.end(), d[i]) - coor.begin();
        ins(1, i);
    }
    dfs(1);
    printf("%lld\n", ans);
}
