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

const int N = 505;

class NETADMIN {
private:
    int n, m, k;
    int cap[N][N];
    vector<pii> E;
    vector<int> g[N];
    int lv[N];
    bool bfs() {
        memset(lv, -1, sizeof lv);
        queue<int> Q;
        lv[1] = 1;
        Q.emplace(1);
        while(!Q.empty()) {
            int u = Q.front(); Q.pop();
            for(int v : g[u]) if(cap[u][v] && lv[v] == -1) {
                lv[v] = lv[u] + 1, Q.emplace(v);
            }
        }
        return lv[n+1] != -1;
    }
    int dfs(int u = 1, int f = INF) {
        if(f == 0) return 0;
        if(u == n+1) return f;
        int flow = 0;
        for(int v : g[u]) if(lv[v] == lv[u] + 1) {
            int now = dfs(v, min(f, cap[u][v]));
            cap[u][v] -= now, cap[v][u] += now, f -= now, flow += now;
        }
        return flow;
    }
    int f(int mid) {
        for(auto x : E) {
            if(x.y == n+1) cap[x.x][x.y] = cap[x.y][x.x] = 1;
            else cap[x.x][x.y] = cap[x.y][x.x] = mid;
        }
        int flow = 0;
        while(bfs()) flow += dfs();
        return flow;
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> m >> k;
        for(int i = 0, val; i < k; ++i) {
            cin >> val;
            E.emplace_back(val, n+1);
            g[val].emplace_back(n+1), g[n+1].emplace_back(val);
        }
        for(int i = 0, u, v; i < m; ++i) {
            cin >> u >> v;
            E.emplace_back(u, v);
            g[u].emplace_back(v), g[v].emplace_back(u);
        }
        int l = 1, r = k;
        while(l < r) {
            int mid = l + r >> 1;
            if(f(mid) >= k) r = mid;
            else l = mid+1;
        }
        cout << r << endl;
    }
};