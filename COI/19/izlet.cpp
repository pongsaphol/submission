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

const int N = 3e3+5;

class TaskA {
private:
    int t, n, st;
    int arr[N][N];
    int par[N], col[N], scol;
    int find(int u) { return par[u] = par[u] == u ? u : find(par[u]); }
    bool check[N];
    int cnt = 1;
    vector<int> g[N], ng[N];
    int z;
    int dfs_fill(int u, int p) {
        bool that = false;
        if(!check[col[u]]) check[col[u]] = true, that = true, cnt++;
        if(cnt != arr[z][u]) {
            if(that) cnt--, check[col[u]] = false;
            return col[u];
        }
        for(int v : ng[u]) if(v != p) {
            int val = dfs_fill(v, u);
            if(val != -1) {
                if(that) cnt--, check[col[u]] = false;
                return val;
            }
        }
        if(that) cnt--, check[col[u]] = false;
        return -1;
    }
    vector<pii> ans;
    bool visit[N];
    void dfs(int u) {
        visit[u] = true;
        if(u != st) {
            z = u;
            for(int v : ng[u]) {
                int val = dfs_fill(v, u);
                if(val != -1) {
                    col[u] = val;
                    break;
                }
            }
            if(!col[u]) col[u] = ++scol;
        }
        for(int v : g[u]) if(!visit[v]) {
            ng[u].emplace_back(v), ng[v].emplace_back(u);
            ans.emplace_back(u, v);
            dfs(v);
        }
    }
    void dfs2(int u, int p) {
        bool that = false;
        if(!check[col[u]]) check[col[u]] = true, that = true, cnt++;
        if(cnt != arr[z][u]) cerr << "FUCK -> " << z << ' ' << u << "->" << cnt << endl;
        for(int v : ng[u]) if(v != p) dfs2(v, u);
        if(that) cnt--, check[col[u]] = false;
    }
public:
    void solve(istream& cin, ostream& cout) {
        iota(par, par+N, 0);
        cin >> t >> n;
        for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) {
                int u = find(i), v = find(j);
                if(u != v) par[u] = v;
            }
            st = find(i);
        }
        for(int i = 1; i <= n; ++i) for(int j = i+1; j <= n; ++j) if(arr[i][j] == 2) {
            int u = find(i), v = find(j);
            if(u != i || v != j) continue;
            g[u].emplace_back(v), g[v].emplace_back(u);
        }
        col[st] = ++scol;
        dfs(st);
        for(int i = 1; i <= n; ++i) {
            int u = find(i);
            if(u != i) ans.emplace_back(u, i), ng[u].emplace_back(i), ng[i].emplace_back(u);
            cout << (col[i] = col[u]) << ' ';
        }
        cout << endl;
        for(auto x : ans) cout << x.x << ' ' << x.y << endl;
//        cnt = 0;
//        for(int i = 1; i <= n; ++i) z = i, dfs2(i, 0);
    }
};