#include <bits/stdc++.h>
#define long long long
#define pii pair<long, long>
#define x first
#define y second
using namespace std;

const int N = 1<<18;
const long INF = 1e12;

int n, m, s, t;
int dep[N];
vector<pii> g[N];
vector<int> lst;
long d[N];

bool find_path(int u, int p) {
    if(u == t) {
        lst.emplace_back(u);
        return true;
    }
    for(pii v : g[u]) if(v.x != p) {
        d[v.x] = d[u] + v.y;
        bool now = find_path(v.x, u);
        if(now) {
            lst.emplace_back(u);
            return true;
        }
    }
    return false;
}

bool isp[N];
int mxe[N];
int pos[N];

int mic(int u, int p) {
    int mx = 0;
    for(pii v : g[u]) if(v.x != p && !isp[v.x])  
        mx = max(mx, mic(v.x, u) + (int)v.y);
    return mx;
}
pair<pii, pii> nll = make_pair(pii(-INF, 0), pii(-INF, 0));
pair<pii, pii> t1[N<<1], t2[N<<1];

pair<pii, pii> config(pair<pii, pii> a, pair<pii, pii> b) {
    pair<pii, pii> z = nll;
    pii a1 = a.x, a2 = a.y, a3 = b.x, a4 = b.y;
    if(a1.x > z.x.x) swap(a1, z.x);
    if(a1.x > z.y.x) swap(a1, z.y);
    if(a2.x > z.x.x) swap(a2, z.x);
    if(a2.x > z.y.x) swap(a2, z.y);
    if(a3.x > z.x.x) swap(a3, z.x);
    if(a3.x > z.y.x) swap(a3, z.y);
    if(a4.x > z.x.x) swap(a4, z.x);
    if(a4.x > z.y.x) swap(a4, z.y);
    return z;
}

void build(int p = 1, int l = 0, int r = lst.size()-1) {
    if(l == r) {
        t1[p].x = pii(mxe[lst[l]] + d[lst[r]], lst[r]);
        t2[p].x = pii(mxe[lst[l]] - d[lst[r]], lst[l]);
        return;
    }
    int m = l + r >> 1;
    build(p<<1, l, m), build(p<<1|1, m+1, r);
    t1[p] = config(t1[p<<1], t1[p<<1|1]);
    t2[p] = config(t2[p<<1], t2[p<<1|1]);
}

pair<pii, pii> query1(int x, int y, int p = 1, int l = 0, int r = lst.size()-1) {
    if(x > r || l > y) return nll;
    if(x <= l && r <= y) return t1[p];
    int m = l + r >> 1;
    return config(query1(x, y, p<<1, l, m), query1(x, y, p<<1|1, m+1, r));
}

pair<pii, pii> query2(int x, int y, int p = 1, int l = 0, int r = lst.size()-1) {
    if(x > r || l > y) return nll;
    if(x <= l && r <= y) return t2[p];
    int m = l + r >> 1;
    return config(query2(x, y, p<<1, l, m), query2(x, y, p<<1|1, m+1, r));
}

int main() {
    fill_n(t1, N<<1, nll);
    fill_n(t2, N<<1, nll);
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for(int i = 1, u, v, w; i < n; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        g[u].emplace_back(v, w), g[v].emplace_back(u, w);
    }
    find_path(s, 0);
    reverse(lst.begin(), lst.end());
    for(int v : lst) isp[v] = true;
    for(int v : lst) mxe[v] = mic(v, v);
    for(int i = 0; i < lst.size(); ++i) pos[lst[i]] = i;
    build();
    for(int i = 0, a, b; i < m; ++i) {
        scanf("%d %d", &a, &b);
        if(pos[a] > pos[b]) swap(a, b);
        pair<pii, pii> q1 = query1(pos[a], pos[b]);
        pair<pii, pii> q2 = query2(pos[a], pos[b]);
        // cerr << q1.x.x << ' ' << q1.x.y << endl;
        // cerr << q1.y.x << ' ' << q1.y.y << endl;
        // cerr << q2.x.x << ' ' << q2.x.y << endl;
        // cerr << q2.y.x << ' ' << q2.y.y << endl;
        long mx = 0;
        if(q1.x.y != q2.x.y) mx = q1.x.x + q2.x.x;
        else mx = max(q1.x.x + q2.y.x, q1.y.x + q2.x.x);
        printf("%lld\n", mx);
    }
}