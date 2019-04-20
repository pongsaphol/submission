#include <bits/stdc++.h>
#define input() (*istream_iterator<int>(cin))
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

const int N = 1022;

class STEAD {
private:
    int n, m;
    vector<int> g[N];
    int arr[N][25];
    int cap[N][N], sz[N];
    vector<iii> E;
    void addEdge(int u, int v, int w) {
        g[u].emplace_back(v), g[v].emplace_back(u);
        cap[u][v] = w, cap[v][u] = 0;
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
        int ret = 0;
        for(int v : g[u]) if(lv[v] == lv[u] + 1) {
            int now = dfs(v, t, min(flow, cap[u][v]));
            ret += now, flow -= now, cap[u][v] -= now, cap[v][u] += now;
        }
        return ret;
    }
    int maxflow(int s, int t) {
        int flow = 0;
        while(bfs(s, t)) flow += dfs(s, t);
        return flow;
    }
    bool check(int k) {
        for(int z = 1; z+k-1 <= m; ++z) {
            for(int i= 0; i < N; ++i) g[i].clear();     
            for(int i = 1; i <= n; ++i) addEdge(0, i, 1);
            for(int i = 1; i <= m; ++i) addEdge(n+i, n+m+1, sz[i]);
            for(int i = 1; i <= n; ++i) for(int j = z; j <= z+k-1; ++j) 
                addEdge(i, arr[i][j] + n, 1);
            if(maxflow(0, n+m+1) == n) return true;
        } 
        return false;
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> m;
        for(int i = 1; i <= n; ++i) 
            for(int j = 1; j <= m; ++j) cin >> arr[i][j];
        for(int i = 1; i <= m; ++i) cin >> sz[i];
        int l = 1, r = m;
        while(l < r) {
            int m = l + r >> 1;
            if(check(m)) r = m;
            else l = m+1;
        }
        cout << r << endl;
    }
};