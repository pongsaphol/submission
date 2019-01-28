#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define iii tuple<int, int, int, int>
#define long long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;
const long MOD = 1e9+7, LINF = 1e18 + 1e16;
const int INF = 1e9+1;
const double EPS = 1e-10;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

const int N = 1<<18;

int n, m;

#define var int p = 1, int l = 1, int r = n
#define mid (l + r >> 1)
#define lb p<<1, l, mid
#define rb p<<1|1, mid+1, r

class TaskF {
private:
    int H[N];
    vector<pii> g[N];
    vector<iii> E;
    int dsu(int u) { return H[u] = H[u] == u ? u : dsu(H[u]); }
    int par[N], rot[N], spi[N], pos[N], dep[N];
    pii anc[N][18];
    int dfs_sz(int u, int p) {
        dep[u] = dep[p] + 1, par[u] = p;
        int sum = 1; pii mx(0, -1);
        for(int i = 1; i < 18; ++i) anc[u][i] = pii(anc[anc[u][i-1].x][i-1].x,
                max(anc[u][i-1].y, anc[anc[u][i-1].x][i-1].y));
        for(pii v : g[u]) if(v.x != p) {
            anc[v.x][0] = pii(u, v.y);
            int now = dfs_sz(v.x, u);
            sum += now;
            if(now > mx.x) mx = pii(now, v.x);
        }
        spi[u] = mx.y;
        return sum;
    }
    void hld() {
        dfs_sz(1, 0);
        for(int u = 1, idx = 0; u <= n; ++u) if(spi[par[u]] != u) {
            for (int v = u; v != -1; v = spi[v]) pos[v] = ++idx, rot[v] = u;
        }
    }
    int ans[N];
    int t[N<<1], lz[N<<1];
    void push(var) {
        if(!lz[p] || t[p]) return;
        t[p] = lz[p];
        if(l != r) {
            if(!lz[p<<1]) lz[p<<1] = lz[p];
            if(!lz[p<<1|1]) lz[p<<1|1] = lz[p];
        }
        lz[p] = 0;
    }
    template<typename T>
    void travel(int x, int y, const T &f, var) {
        push(p, l, r);
        if(x > r || l > y) return;
        if(x <= l && r <= y) return f(p, l, r);
        travel(x, y, f, lb), travel(x, y, f, rb);
    }
public:
    void solve(istream& cin, ostream& cout) {
        iota(H, H+N, 0);
        fill_n(ans, N, -2);
        cin >> n >> m;
        for(int i = 0, u, v, w; i < m; ++i) {
            cin >> u >> v >> w;
            E.emplace_back(u, v, w, i);
        }
        sort(all(E), [&](const iii &a, const iii &b) { return get<2>(a) < get<2>(b); });
        for(auto &x : E) {
            int u, v, w, idx; tie(u, v, w, idx) = x;
            int a = dsu(u), b = dsu(v);
            if(a != b) H[a] = b, g[u].emplace_back(v, w), g[v].emplace_back(u, w);
        }
        hld();
        iota(H, H+N, 0);
        for(auto &x : E) {
            int u, v, w, idx; tie(u, v, w, idx) = x;
            int a = dsu(u), b = dsu(v);
            if(a == b) {
                a = u, b = v;
                ans[idx] = 0;
                if(dep[u] < dep[v]) swap(u, v);
                for(int i = 17; ~i; --i) if(dep[anc[u][i].x] >= dep[v]) {
                    ans[idx] = max(ans[idx], anc[u][i].y);
                    u = anc[u][i].x;
                }
                if(u != v) {
                    for(int i = 17; ~i; --i) if(anc[u][i].x != anc[v][i].x) {
                        ans[idx] = max({ans[idx], anc[u][i].y, anc[v][i].y});
                        u = anc[u][i].x, v = anc[v][i].x;
                    }
                    ans[idx] = max({anc[u][0].y, anc[v][0].y, ans[idx]});
                }
                ans[idx]--;
                while(rot[a] != rot[b]) {
                    if(dep[rot[a]] < dep[rot[b]]) swap(a, b);
                    travel(pos[rot[a]], pos[a], [&](var) {
                        if(!lz[p]) lz[p] = w;
                        push(p, l, r);
                    });
                    a = par[rot[a]];
                }
                if(dep[a] > dep[b]) swap(a, b);
                travel(pos[a]+1, pos[b], [&](var) {
                    if(!lz[p]) lz[p] = w;
                    push(p, l, r);
                });
            } else H[a] = b;
        }
        for(auto &x : E) {
            int u, v, w, idx; tie(u, v, w, idx) = x;
            if(ans[idx] != -2) continue;
            if(par[u] != v) swap(u, v);
            travel(pos[u], pos[u], [&](var) { ans[idx] = t[p] - 1; });
        }
        for(int i = 0; i < m; ++i) cout << ans[i] << ' ';
    }
};
