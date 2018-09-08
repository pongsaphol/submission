#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int n, m, q, A[N];
int par[N][18], dep[N];
vector<int> g[N];
set<int> pos[N], lca_pos[N];

void init_lca(int u, int p) {
    for(int i = 1; i < 18; ++i) par[u][i] = par[par[u][i-1]][i-1];
    for(int v : g[u]) if(v != p) par[v][0] = u, dep[v] = dep[u] + 1, init_lca(v, u);
}

int get_lca(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    for(int i = 17; ~i; --i) if(dep[par[u][i]] >= dep[v]) u = par[u][i];
    if(u == v) return u;
    for(int i = 17; ~i; --i) if(par[u][i] != par[v][i]) u = par[u][i], v = par[v][i];
    return par[u][0];
}

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        g[u].emplace_back(v), g[v].emplace_back(u);
    }
    for(int i = 1; i <= n; ++i) pos[i].emplace(n+1), lca_pos[i].emplace(n+1);
    init_lca(1, 0);
    for(int i = 1; i <= m; ++i) scanf("%d", A+i), pos[A[i]].emplace(i);
    for(int i = 1; i < m; ++i) lca_pos[get_lca(A[i], A[i+1])].emplace(i);
    for(int i = 0, tp, l, r, v; i < q; ++i) {
        scanf("%d", &tp);
        if(tp == 1) {
            scanf("%d %d", &tp, &v);
            pos[A[tp]].erase(tp);
            if(tp != 1) lca_pos[get_lca(A[tp], A[tp-1])].erase(tp-1);
            if(tp != m) lca_pos[get_lca(A[tp], A[tp+1])].erase(tp); 
            A[tp] = v;
            pos[A[tp]].emplace(tp);
            if(tp != 1) lca_pos[get_lca(A[tp], A[tp-1])].emplace(tp-1);
            if(tp != m) lca_pos[get_lca(A[tp], A[tp+1])].emplace(tp);
        } else {
            scanf("%d %d %d", &l, &r, &v);
            int a1 = *pos[v].lower_bound(l), a2 = *lca_pos[v].lower_bound(l);
            if(a1 <= r) printf("%d %d\n", a1, a1);
            else if(a2 < r) printf("%d %d\n", a2, a2+1);
            else puts("-1 -1");
        }
    } 
}
