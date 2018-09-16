#include <bits/stdc++.h>
using namespace std;

#define long long long
#define pii pair<long, long>
#define x first
#define y second

const int N = 1e5+5;

struct item {
    pii line;
    item *l, *r;
    item(pii line, item* l, item* r) : line(line), l(l), r(r) {}
};

int n;
long d[N], dp[N];
item* ver[N];
vector<pii> g[N];
pii A[N];

long get(pii a, long x) { return a.x * x + a.y; }

item* newleaf(pii v) { return new item(v, nullptr, nullptr); }
item* newpar(pii v, item* l, item *r) { return new item(v, l, r); }

item* update(pii v, item *p, int l = 1, int r = 1e9) {
    if(p == NULL) return newleaf(v);
    if(get(v, l) > get(p->line, l) && get(v, r) > get(p->line, r)) return p;
    if(get(v, l) < get(p->line, l) && get(v, r) < get(p->line, r)) return newpar(v, p->l, p->r);
    pii ret = p->line;
    int m = l + r >> 1;
    if(get(ret, l) > get(v, l)) swap(ret, v);
    if(get(ret, m) > get(v, m)) return newpar(v, update(ret, p->l, l, m), p->r);
    return newpar(ret, p->l, update(v, p->r, m+1, r));
}

long query(long v, item *p, int l = 1, int r = 1e9) {
    if(p == NULL) return 1e18;
    long mn = get(p->line, v);
    int m = l + r >> 1;
    if(v <= m) return min(mn, query(v, p->l, l, m));
    return min(mn, query(v, p->r, m+1, r));
}

void dfs(int u, int p) {
    dp[u] = 1ll * d[u] * A[u].y + A[u].x + query(A[u].y, ver[p]);
    ver[u] = update(pii(-d[u], dp[u]), ver[p]);
    for(pii v : g[u]) if(v.x != p) d[v.x] = d[u] + v.y, dfs(v.x, u);
}

int main() {
    scanf("%d", &n);
    for(int i = 1, u, v, w; i < n; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    for(int i = 2, a, b; i <= n; ++i) scanf("%d %d", &a, &b), A[i] = pii(a, b);
    ver[1] = newleaf(pii(0, 0));
    for(pii v : g[1]) d[v.x] = v.y, dfs(v.x, 1);
    for(int i = 2; i <= n; ++i) printf("%lld ", dp[i]);
}
