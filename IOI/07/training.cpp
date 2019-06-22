#include <bits/stdc++.h>
#define iii tuple<int, int, int>
using namespace std;

const int N = 1e3+5;

int n, m, ans;
vector<int> g[N];
vector<iii> vec, pre[N];
int dep[N], par[N][10];

void init_lca(int u, int p) {
    dep[u] = dep[p] + 1, par[u][0] = p;
    for(int i = 1; i < 10; ++i) par[u][i] = par[par[u][i-1]][i-1];
    if(p) g[u].erase(find(g[u].begin(), g[u].end(), p));
    for(int v : g[u]) init_lca(v, u);
}

int lca(int a, int b) {
    if(dep[a] < dep[b]) swap(a, b);
    for(int i = 9; ~i; --i) if(dep[par[a][i]] >= dep[b]) a = par[a][i];
    if(a == b) return a;
    for(int i = 9; ~i; --i) if(par[a][i] != par[b][i]) a = par[a][i], b = par[b][i];
    return par[a][0];
}

int dp[N][1<<10];
int pos[N];
int ss[N];

void solve(int u) {
    int sz = g[u].size();
    int sbit = 1 << sz;
    ss[u] = sbit-1;
    for(int i = 0; i < sz; ++i) pos[g[u][i]] = i;
    for(int v : g[u]) {
        solve(v);
        for(int i = 0; i < sbit; ++i) if(i >> pos[v] & 1) dp[u][i] = max(dp[u][i], dp[u][i ^ (1 << pos[v])] + dp[v][ss[v]]);
    }
    for(auto x : pre[u]) {
        int a, b, w; tie(a, b, w) = x;
        int prea = -1, preb = -1;
        int suma = 0, sumb = 0;
        while(a != u) {
            if(prea != -1) suma += dp[a][ss[a] ^ (1 << pos[prea])];
            else suma += dp[a][ss[a]];
            prea = a;
            a = par[a][0];
        }
        while(b != u) {
            if(preb != -1) sumb += dp[b][ss[b] ^ (1 << pos[preb])];
            else sumb += dp[b][ss[b]];
            preb = b;
            b = par[b][0];
        }
        int bt = 0;
        if(prea != -1) bt |= (1 << pos[prea]);
        if(preb != -1) bt |= (1 << pos[preb]);
        for(int i = 0; i < sbit; ++i) if((i & bt) == bt) {
            dp[u][i] = max(dp[u][i], dp[u][i ^ bt] + suma + sumb + w);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0, u, v, w; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        if(!w) g[u].emplace_back(v), g[v].emplace_back(u);
        else vec.emplace_back(u, v, w);
    }
    init_lca(1, 0);
    int sum = 0;
    for(auto x : vec) {
        int u, v, w; tie(u, v, w) = x;
        int dist = dep[u] + dep[v] - 2 * dep[lca(u, v)];
        if(dist & 1) ans += w;
        else {
            pre[lca(u, v)].emplace_back(x);
            sum += w;
        }
    }
    solve(1);
    printf("%d\n", ans + (sum - dp[1][ss[1]]));
}