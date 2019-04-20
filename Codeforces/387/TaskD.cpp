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

const int N = 1e3+5;

class TaskD {
private:
    int n, m, ans = INF;
    bool z[N][N];
    vector<int> adj[N], g[N];
    int cap[N][N];
    int lv[N];
    void addEdge(int u, int v) {
        g[u].emplace_back(v), g[v].emplace_back(u);
        cap[u][v] = 1, cap[v][u] = 0;
    }
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
        int ret = 0;
        for(int v : g[u]) if(lv[v] == lv[u] + 1) {
            int now = dfs(v, t, min(flow, cap[u][v]));
            flow -= now, ret += now, cap[u][v] -= now, cap[v][u] += now;
        }
        return ret;
    }
    int maxflow(int s, int t) {
        int flow = 0;
        while(bfs(s, t)) flow += dfs(s, t);
        return flow;
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> m;
        for(int i = 0, u, v; i < m; ++i) {
            cin >> u >> v;
            z[u][v] = true;
            adj[u].emplace_back(v);
        }
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < N; ++j) g[j].clear();
            int same = 0;
            for(int j = 1; j <= n; ++j) {
                if(i == j) same += z[i][j];
                else same += z[i][j] + z[j][i];
            }
            for(int j = 1; j <= n; ++j) if(j != i) {
                addEdge(0, j), addEdge(j+n, n<<1|1);
                for(int v : adj[j]) if(v != i) addEdge(j, v+n);
            }
            int flow = maxflow(0, n<<1|1);
            int val = (2*n - 1 - same) + (m - same - flow) + (n - 1 - flow);
            ans = min(ans, val);
        }
        cout << ans << endl;
    }
};