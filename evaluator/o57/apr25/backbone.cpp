#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define x first
#define y second

const int N = 2e2+5;

int n, m;
bool check[N];
int par[N][8], dep[N];
vector<int> g[N], pos[N];
vector<pii> que;

void init_lca(int u, int p) {
    par[u][0] = p, dep[u] = dep[p] + 1;
    for(int i = 1; i < 8; ++i) par[u][i] = par[par[u][i-1]][i-1];
    for(int v : g[u]) if(v != p) init_lca(v, u);
}

int get_lca(int a, int b) {
    if(dep[a] < dep[b]) swap(a, b);
    for(int i = 7; ~i; --i) if(dep[par[a][i]] >= dep[b]) a = par[a][i];
    if(a == b) return a;
    for(int i = 7; ~i; --i) if(par[a][i] != par[b][i]) a = par[a][i], b = par[b][i];
    return par[a][0];
}

int bin_lift(int u, int h) {
    for(int i = 7; ~i; --i) if(h >> i & 1) u = par[u][i];
    return u;
}

vector<pii> ans(11), ret;

void solve(int u) {
    if(u == m) {
        if(ans.size() > ret.size()) ans = ret;
        return;
    }
    if(ret.size() > 10) return;
    if(check[u]) return void(solve(u+1));
    int a, b; tie(a, b) = que[u];
    int lca = get_lca(a, b);
    int x = bin_lift(a, dep[a] - dep[lca] - 1), y = bin_lift(b, dep[b] - dep[lca] - 1);
    auto f = [&](int z) {
        ret.emplace_back(z, par[z][0]);
        vector<int> res;
        for(int v : pos[z]) if(!check[v]) res.emplace_back(v), check[v] = true;
        solve(u+1);
        for(int v : res) check[v] = false;
        ret.pop_back();
    };
    if(a != lca) f(x);
    if(b != lca) f(y);
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1, a, b; i < n; ++i) {
        scanf("%d %d", &a, &b);
        g[a].emplace_back(b), g[b].emplace_back(a); 
    }
    init_lca(1, 0);
    for(int i = 0, a, b; i < m; ++i) {
        scanf("%d %d", &a, &b);
        que.emplace_back(a, b);
    }
    sort(que.begin(), que.end(), [&](const pii &a, const pii &b) { return dep[get_lca(a.x, a.y)] > dep[get_lca(b.x, b.y)]; });
    for(int i = 0, a, b; i < m; ++i) {
        tie(a, b) = que[i];
        int lca = get_lca(a, b);
        while(a != lca) pos[a].emplace_back(i), a = par[a][0];
        while(b != lca) pos[b].emplace_back(i), b = par[b][0];
    }
    solve(0);
    printf("%d\n", (int)ans.size());
    for(pii v : ans) printf("%d %d\n", v.x, v.y);
}
