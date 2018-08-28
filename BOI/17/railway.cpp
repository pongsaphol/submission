#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define x first
#define y second

const int N = 1e5+5;

int n, m, k;
int in[N], out[N], sz[N], pos[N], idx[N];
vector<pii> g[N];
vector<int> node[N];
int szn[N], cnt[N], ans;
int rans[N];

void dfs(int u, int p) {
    static int ptr = 0;
    in[u] = ++ptr, pos[ptr] = u, sz[u] = 1;
    if(p) for(auto it = g[u].begin(); it != g[u].end(); ++it) if(it->x == p) { g[u].erase(it); break; }
    for(auto &v : g[u]) {
        idx[v.x] = v.y;
        dfs(v.x, u);
        sz[u] += sz[v.x];
        if(sz[v.x] > sz[g[u][0].x]) swap(v, g[u][0]);
    } 
    out[u] = ptr;
}

void add(int x) {
    cnt[x]++;
    if(cnt[x] == 1) ans++;
    if(cnt[x] == szn[x]) ans--;
}

void del(int x) {
    cnt[x]--;
    if(cnt[x] == 0) ans--;
    if(cnt[x] == szn[x]-1) ans++;
}

void sack(int u, bool keep) {
    for(auto v : g[u]) if(v != g[u][0]) sack(v.x, false);
    if(g[u].size()) sack(g[u][0].x, true);
    for(int v : node[u]) add(v);
    for(auto v : g[u]) if(v != g[u][0])
        for(int i = in[v.x]; i <= out[v.x]; ++i) for(auto x : node[pos[i]]) add(x);
    rans[idx[u]] = ans;
    if(!keep) for(int i = in[u]; i <= out[u]; ++i) for(auto x : node[pos[i]]) del(x);
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        g[u].emplace_back(v, i), g[v].emplace_back(u, i);
    } 
    dfs(1, 0);
    for(int i = 0; i < m; ++i) {
        int q; scanf("%d", &q);
        szn[i] = q;
        while(q--) {
            int v; scanf("%d", &v);
            node[v].emplace_back(i);
        }
    }
    sack(1, false);
    vector<int> A;
    for(int i = 1; i < n; ++i) if(rans[i] >= k) A.emplace_back(i);
    printf("%d\n", A.size());
    for(int v : A) printf("%d ", v);
}