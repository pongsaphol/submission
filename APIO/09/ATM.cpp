#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;

int n, m, A[N], s, cp;
bool pub[N], npub[N];
vector<int> g[N], ng[N];

int dist[N], low[N];
int ptr, id[N];
int sumb[N];
bool instack[N];

void scc(int u) {
    static stack<int> S;
    static int idx = 0;
    dist[u] = low[u] = ++idx;
    S.emplace(u);
    instack[u] = true;
    for(int v : g[u]) {
        if(!dist[v]) scc(v), low[u] = min(low[u], low[v]);
        else if(instack[v]) low[u] = min(low[u], dist[v]);
    }
    if(low[u] == dist[u]) {
        ptr++;
        do id[S.top()] = ptr, instack[S.top()] = false, S.pop(); while(!id[u]);
    }
}

#define pii pair<int, bool>
#define x first
#define y second
pii dp[N];

pii dfs(int u) {
    if(dp[u].x != -1) return dp[u];
    pii now = pii(0, npub[u]);
    for(int v : ng[u]) {
        pii ret = dfs(v);
        if(!ret.y) continue;
        now.y |= ret.y;
        now.x = max(now.x, ret.x);
    }
    now.x += sumb[u];
    return dp[u] = now;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0, u, v; i < m; ++i) {
        scanf("%d %d", &u, &v);
        g[u].emplace_back(v);
    } 
    for(int i = 1; i <= n; ++i) scanf("%d", A+i);
    scanf("%d %d", &s, &cp);
    for(int i = 0, val; i < cp; ++i) scanf("%d", &val), pub[val] = true;
    scc(s);
    for(int i = 1; i <= n; ++i) if(id[i]) {
        npub[id[i]] |= pub[i];
        sumb[id[i]] += A[i];
        for(int v : g[i]) if(id[v] != id[i] and id[v]) ng[id[i]].emplace_back(id[v]);
    }
    for(int i = 1; i <= ptr; ++i) {
        dp[i].x = -1;
        sort(ng[i].begin(), ng[i].end());
        ng[i].resize(unique(ng[i].begin(), ng[i].end()) - ng[i].begin());
    }
    pii now = dfs(id[s]);
    printf("%d\n", now.x);
}
