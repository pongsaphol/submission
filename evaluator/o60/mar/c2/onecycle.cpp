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

const int N = 3005;

class onecycle {
private:
    int n;
    vector<iii> vec, del, ans;
    vector<pii> g[N];
    int H[N];
    int find(int u) { return H[u] = H[u] == u ? u : find(H[u]); }
    int dep[N], par[N][12], d[N];
    void init_lca(int u, int p) {
        dep[u] = dep[p] + 1, par[u][0] = p;
        for(int i = 1; i < 12; ++i) par[u][i] = par[par[u][i-1]][i-1];
        for(pii v : g[u]) if(v.x != p) d[v.x] = d[u] + v.y, init_lca(v.x, u);
    }
    int get_lca(int a, int b) {
        if(dep[a] < dep[b]) swap(a, b);
        for(int i = 11; ~i; --i) if(dep[par[a][i]] >= dep[b]) a = par[a][i];
        if(a == b) return a;
        for(int i = 11; ~i; --i) if(par[a][i] != par[b][i]) a = par[a][i], b = par[b][i];
        return par[a][0];
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        iota(H, H+N, 0);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1, val; j <= n; ++j) if(i != j) {
                cin >> val;
                if(j > i) vec.emplace_back(i, j, val);
            }
        }
        sort(all(vec), [&](const iii &a, const iii &b) { return get<2>(a) < get<2>(b); });
        for(auto x : vec) {
            int u, v, w; tie(u, v, w) = x;
            int a = find(u), b = find(v);
            if(a != b) H[a] = b, g[u].emplace_back(v, w), g[v].emplace_back(u, w), ans.emplace_back(x);
            else del.emplace_back(x);
        }
        init_lca(1, 0);
        for(auto x : del) {
            int u, v, w; tie(u, v, w) = x;
            int dist = d[u] + d[v] - 2*d[get_lca(u, v)];
            if(dist != w) {
                ans.emplace_back(x);
                break;
            }
        }
        sort(all(ans));
        for(auto x : ans) {
            int u, v, w; tie(u, v, w) = x;
            cout << u << ' ' << v << ' ' << w << endl;
        }
    }
};