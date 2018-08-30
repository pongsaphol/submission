#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define x first
#define y second

const int N = 205;
const int M = 305;

int n, m;
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

bool check[M];
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
    auto f = [&](int x) {
        if(x == lca) return;
        int jump = dep[x] - dep[lca] - 1;
        for(int i = 7; ~i; --i) if(jump >> i & 1) x = par[x][i];
        ret.emplace_back(x, par[x][0]);
        vector<int> res;
        for(int v : pos[x]) if(!check[v]) res.emplace_back(v), check[v] = true;
        solve(u+1);
        for(int v : res) check[v] = false;
        ret.pop_back();
    };
    f(a), f(b);
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
