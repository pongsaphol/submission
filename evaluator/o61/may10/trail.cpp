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

const int N = 2e2+5;

class trail {
private:
    int n, m, p, q;
    int ans, d[N][N], arr[N][N];
    vector<int> g[N];
    int cap[N][N];
    void addEdge(int u, int v) {
        cap[u][v] = 1, cap[v][u] = 0;
        g[u].emplace_back(v), g[v].emplace_back(u);
    }
    int lv[N];
    bool bfs(int s, int t) {
        memset(lv, -1, sizeof lv);
        queue<int> Q; Q.emplace(s), lv[s] = 0;
        while(!Q.empty()) {
            int u = Q.front(); Q.pop();
            for(int v : g[u]) if(cap[u][v] && lv[v] == -1)
                lv[v] = lv[u] + 1, Q.emplace(v);
        }
        return lv[t] != -1;
    }
    int dfs(int u, int t, int flow = INF) {
        if(u == t || !flow) return flow;
        int sum = 0;
        for(int v : g[u]) if(lv[v] == lv[u] + 1) {
            int val = dfs(v, t, min(flow, cap[u][v]));
            cap[u][v] -= val, cap[v][u] += val, flow -= val, sum += val;
        }
        return sum;
    }
    int maxflow(int s, int t) {
        int sum = 0;
        while(bfs(s, t)) sum += dfs(s, t);
        return sum;
    }
    bool f(int flow, int z) {
        for(int i = 0; i < 2*(p+1); ++i) g[i].clear();
        for(int i = 0; i < p; ++i) for(int j = 0; j < p; ++j)
            if(d[arr[z-1][i]][arr[z][j]] <= flow) addEdge(i, j+p);
        for(int i = 0; i < p; ++i) {
            addEdge(p<<1, i);
            addEdge(i+p, p<<1|1);
        }
        return maxflow(p<<1, p<<1|1) == p;
    }
public:
    void solve(istream& cin, ostream& cout) {
        fill_n(d[0], N*N, INF);
        cin >> n >> m >> p >> q;
        for(int i = 0; i < q; ++i) for(int j = 0; j < p; ++j) cin >> arr[i][j];
        for(int i = 0; i < n; ++i) d[i][i] = 0;
        for(int i = 0, u, v, w; i < m; ++i) {
            cin >> u >> v >> w;
            d[u][v] = d[v][u] = min(d[u][v], w);
        }
        for(int k = 0; k < n; ++k) for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j)
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        for(int i = 1; i < q; ++i) {
            int l = 0, r = 1e6;
            while(l < r) {
                int m = l + r >> 1;
                if(f(m, i)) r = m;
                else l = m+1;
            }
            ans += r;
        }
        cout << ans << endl;
    }
};
