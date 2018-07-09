#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1<<19, INF = 1e9;

int n, m, A[N], ans[N];
pii pos[N], t[N<<1];
vector<pii> que[N];

void update(int x, int v, int v2, int p = 1, int l = 1, int r = n) {
    if(l == r) {
        t[p] = pii(v, v2);
        return;
    }
    int m = (l + r) >> 1;
    if(x <= m) update(x, v, v2, p<<1, l, m);
    else update(x, v, v2, p<<1|1, m+1, r);
    t[p] = t[p<<1].x < t[p<<1|1].x ? t[p<<1] : t[p<<1|1]; 
}

pii query(int x, int y, int p = 1, int l = 1, int r = n) {
    if(x > r || l > y) return pii(INF, 0);
    if(x <= l && r <= y) return t[p];
    int m = (l + r) >> 1;
    pii a = query(x, y, p<<1, l, m), b = query(x, y, p<<1|1, m+1, r);
    return a.x < b.x ? a : b;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", A+i);
    scanf("%d", &m);
    for(int i = 1, a, b; i <= m; ++i) {
        scanf("%d %d", &a, &b);
        que[b].emplace_back(a, i);
    }
    for(int i = 1; i <= n; ++i) {
        if(pos[A[i]].y) update(pos[A[i]].y, INF, 0);
        pos[A[i]].x = pos[A[i]].y;
        pos[A[i]].y = i;
        update(i, pos[A[i]].x, A[i]);
        for(auto x : que[i]) {
            pii z = query(x.x, i);
            if(z.x < x.x) ans[x.y] = z.y;
        }
    }
    for(int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
}