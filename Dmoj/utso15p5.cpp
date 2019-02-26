#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define iii tuple<int, int, int>
#define long long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;
const long MOD = 1e9+7, LINF = 1e18 + 1e16;
const int INF = 1e9+1;
const double EPS = 1e-10;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

const int N = 5e4+5;

class utso15p5 {
private:
    int n, m;
    vector<iii> E, nE;
    int P[N];
    int find(int u) { return P[u] = P[u] == u ? u : find(P[u]); }
    int dep[N], par[N][16], mx[N][16];
    vector<pii> g[N];
    void init_lca(int u = 1, int p = 0) {
        dep[u] = dep[p] + 1, par[u][0] = p;
        for(int i = 1; i < 16; ++i) par[u][i] = par[par[u][i-1]][i-1], mx[u][i] = max(mx[u][i-1], mx[par[u][i-1]][i-1]);
        for(pii v : g[u]) if(v.x != p) mx[v.x][0] = v.y, init_lca(v.x, u);
    }
    int get_lca(int a, int b) {
        int now = 0;
        if(dep[a] < dep[b]) swap(a, b);
        for(int i = 15; ~i; --i) if(dep[par[a][i]] >= dep[b]) now = max(now, mx[a][i]), a = par[a][i];
        if(a == b) return now;
        for(int i = 15; ~i; --i) if(par[a][i] != par[b][i]) now = max({now, mx[a][i], mx[b][i]}), a = par[a][i], b = par[b][i];
        return max({now, mx[a][0], mx[b][0]});
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> m;
        for(int i = 0, u, v, w; i < m; ++i) {
            cin >> u >> v >> w;
            E.emplace_back(w, u, v);
        }
        sort(all(E));
        iota(P, P+N, 0);
        int sum = 0;
        for(auto x : E) {
            int w, u, v; tie(w, u, v) = x;
            int a = find(u), b = find(v);
            if(a != b) P[a] = b, g[u].emplace_back(v, w), g[v].emplace_back(u, w), sum += w;
            nE.emplace_back(x);
        }
        int ans = INF;
        int z = find(1);
        for(int i = 2; i <= n; ++i) if(find(i) != z) {
            cout << -1 << endl;
            return;
        }
        init_lca();
        for(auto x : nE) {
            int w, u, v; tie(w, u, v) = x;
            int lca = get_lca(u, v);
            if(w == lca) continue;
            ans = min(ans, sum + w - get_lca(u, v));
        }
        if(ans == INF) ans = -1;
        cout << ans << endl;
    }
};