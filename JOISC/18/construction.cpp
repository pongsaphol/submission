#include <bits/stdc++.h>
using namespace std;

#define long long long 
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define x first
#define y second

const int N = 1e5+5;

int n;
int A[N];
vector<int> g[N];
deque<pii> chain[N];

int dep[N], par[N], rot[N], spi[N], pos[N];

int dfs_sz(int u, int p) {
    dep[u] = dep[p] + 1, par[u] = p;
    int sz = 1; pii mx(0, -1);
    for(int v : g[u]) {
        int now = dfs_sz(v, u);
        sz += now; 
        if(mx.x < now) mx = pii(now, v);
    }
    spi[u] = mx.y;
    return sz;
}

void hld() {
    dfs_sz(1, 0);
    for(int u = 1, idx = 0; u <= n; ++u) if(spi[par[u]] != u) 
        for(int v = u; v != -1; v = spi[v]) pos[v] = ++idx, rot[v] = u;
}

long query(int u) {
    vector<pii> ret; vector<int> coor;
    while(u) {
        int sz = dep[u] - dep[rot[u]] + 1;
        vector<pii> now;
        for(auto x : chain[rot[u]]) {
            if(x.y < sz) now.emplace_back(x), sz -= x.y;
            else { now.emplace_back(x.x, sz); break; }
        }
        reverse(all(now));
        for(auto x : now) 
            ret.emplace_back(x), coor.emplace_back(x.x);
        u = par[rot[u]];
    }
    sort(all(coor)), coor.resize(unique(all(coor)) - coor.begin());
    long sum = 0;
    vector<int> t((int)coor.size(), 0);
    auto updt = [&](int x, int v) { for(int i = x+1; i <= coor.size(); i += i & -i) t[i-1] += v; };
    auto quet = [&](int x) { long sum = 0; for(int i = x+1; i > 0; i -= i & -i) sum += t[i-1]; return sum; };
    auto getp = [&](int x) { return lower_bound(all(coor), x) - coor.begin(); };
    for(auto x : ret) {
        sum += quet(getp(x.x)-1) * x.y;
        updt(getp(x.x), x.y);
    } 
    return sum;
}

void update(int u, int v) {
    chain[rot[u]].emplace_back(A[u], 1);
    while(u) {
        int sz = dep[u] - dep[rot[u]] + 1;
        while(!chain[rot[u]].empty()) {
            if(chain[rot[u]].front().y <= sz) sz -= chain[rot[u]].front().y, chain[rot[u]].pop_front();
            else {  chain[rot[u]].front().y -= sz; break; }
        }
        chain[rot[u]].emplace_front(v, dep[rot[u]] - dep[u] + 1);
        u = par[rot[u]];
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", A+i);
    vector<pii> E;
    for(int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        E.emplace_back(u, v);
        g[u].emplace_back(v);
    }
    hld();
    chain[1].emplace_back(A[1], 1);
    for(auto x : E) {
        int u, v; tie(u, v) = x;
        printf("%lld\n", query(u));
        update(v, A[v]);
    }
}
