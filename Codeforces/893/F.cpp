#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1<<17, INF = 1e9+1;

int n, m, r, A[N];
int dep[N], in[N], out[N];
vector<int> ver, pref[N<<1];
vector<pii> t[N<<1];
vector<vector<int> > g(N);

void dfs(int u, int p) {
    dep[u] = dep[p] + 1;
    ver.emplace_back(u);
    in[u] = ver.size()-1;
    for(auto v : g[u]) if(v ^ p) dfs(v, u);
    out[u] = ver.size()-1;
}

void build() {
    for(int i = 0; i < n; ++i) t[i+n].emplace_back(dep[ver[i]], A[ver[i]]), pref[i+n].emplace_back(A[ver[i]]);
    for(int i = n-1; i; --i) {
        merge(t[i<<1].begin(), t[i<<1].end(), t[i<<1|1].begin(), t[i<<1|1].end(), back_inserter(t[i]));
        pref[i].emplace_back(t[i][0].y);
        for(int j = 1; j < t[i].size(); ++j) pref[i].emplace_back(min(pref[i][j-1], t[i][j].y));
    }
}

int query(int l, int r, int v) {
    int mn = INF;
    auto cal = [&](int p) {
        int idx = upper_bound(t[p].begin(), t[p].end(), pii(v, INF)) - t[p].begin() - 1;
        if(~idx) mn = min(mn, pref[p][idx]);
    };
    for(l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
        if(l & 1) cal(l++);
        if(r & 1) cal(--r);
    }
    return mn;
}

int main() {
    scanf("%d %d", &n, &r);
    for(int i = 1; i <= n; ++i) scanf("%d", A+i);
    for(int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        g[u].emplace_back(v), g[v].emplace_back(u);
    }
    dfs(r, 0);
    build();
    scanf("%d", &m);
    int last = 0;
    while(m--) {
        int u, k; scanf("%d %d", &u, &k);
        u = (u + last) % n + 1;
        k = (k + last) % n;
        printf("%d\n", last = query(in[u], out[u], dep[u] + k));
    }
}