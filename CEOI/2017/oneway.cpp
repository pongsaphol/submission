#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1e5+5;

int n, m, p, d1[N], d2[N];
char Answer[N];
bitset<N> check, checkE;
pii E[N];
vector<pii> g[N];

void dfs(int u, int p) {
    check[u] = true;
    for(pii v : g[u]) if(v.x != p) {
        if(check[v.x]) { if(E[v.y].x == u) swap(E[v.y].x, E[v.y].y); }
        else checkE[v.y] = true, dfs(v.x, u);
    }
}

void solve(int u, int p) {
    check[u] = false;
    for(pii v : g[u]) if(v.x != p) if(check[v.x]) {
        solve(v.x, u);
        Answer[v.y] = 'B';
        d1[u] += d1[v.x], d2[u] += d2[v.x];
        if(d1[v.x] || !d2[v.x]) continue;
        Answer[v.y] = (d2[v.x] > 0 ? v.x : u) == E[v.y].x ? 'R' : 'L'; 
    } 
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0, u, v; i < m; ++i) {
        scanf("%d %d", &u, &v);
        g[u].emplace_back(v, i), g[v].emplace_back(u, i);
        E[i] = pii(u, v);
    }
    for(int i = 1; i <= n; ++i) if(!check[i]) dfs(i, 0);
    for(int i = 0; i < m; ++i) if(!checkE[i]) Answer[i] = 'B', d1[E[i].x]++, d1[E[i].y]--;
    scanf("%d", &p);
    for(int i = 0, a, b; i < p; ++i) {
        scanf("%d %d", &a, &b);
        d2[a]++, d2[b]--;
    }
    for(int i = 1; i <= n; ++i) if(check[i]) solve(i, 0);
    printf("%s", Answer);
}