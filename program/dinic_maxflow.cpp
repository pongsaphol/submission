#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define long long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;
const long MOD = 1e9+7, LINF = 1e18 + 1e16;
const int INF = 1e9+1;
const double EPS = 1e-10;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

const int N = 105;

int idx;
int n, m, s, t;

class maxflow_dinic_re {
private:
    vector<int> g[N];
    int cap[N][N], lv[N];
    bool bfs() {
        fill_n(lv, N, -1);
        lv[s] = 0;
        queue<int> Q;
        Q.emplace(s);
        while(!Q.empty()) {
            int u = Q.front(); Q.pop();
            for(int v : g[u]) if(lv[v] == -1 && cap[u][v]) {
                lv[v] = lv[u] + 1;
                Q.emplace(v);
            }
        }
        return lv[t] != -1;
    }
    int dfs(int u = s, int bflow = INF) {
        if(!bflow) return 0;
        if(u == t) return bflow;
        int flow = 0;
        for(int v : g[u]) if(lv[v] - lv[u] == 1) {
            int x = dfs(v, min(bflow, cap[u][v]));
            cap[u][v] -= x, cap[v][u] += x;
            bflow -= x, flow += x;
        }
        return flow;
    }
    int dinic() {
        int flow = 0;
        while(bfs()) flow += dfs();
        return flow;
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        if (!n) return;
        cin >> s >> t >> m;
        for(int i = 0, u, v, w; i < m; ++i) {
            cin >> u >> v >> w;
            cap[u][v] += w, cap[v][u] += w;
            g[u].emplace_back(v), g[v].emplace_back(u);
        }
        cout << "Network " << ++idx << '\n';
        cout << "The bandwidth is " << dinic() << ".\n\n";
    }
};