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

const int N = 1e5+5;

class hiking {
private:
    int n, m, k;
    int low[N], pre[N], d[N];
    vector<int> g[N], art;
    bool tarjan(int u, int p) {
        static int idx = 0;
        low[u] = pre[u] = ++idx;
        bool status = u == n;
        for(int v : g[u]) if(!pre[v]) {
            bool now = tarjan(v, u);
            low[u] = min(low[u], low[v]), status |= now;
            if(low[v] >= pre[u] && now && u != 1) art.emplace_back(d[u]);
        } else if(v != p) low[u] = min(low[u], pre[v]);
        return status;
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> m >> k;
        for(int i = 0, u, v; i < m; ++i) {
            cin >> u >> v;
            g[u].emplace_back(v), g[v].emplace_back(u);
        }
        queue<int> Q; Q.emplace(1), d[1] = 1;
        while(!Q.empty()) {
            int u = Q.front(); Q.pop();
            for(int v : g[u]) if(!d[v]) d[v] = d[u] + 1, Q.emplace(v);
        }
        tarjan(1, 0);
        sort(all(art));
        int ans = 0, pre = -INF;
        for(auto x : art) if(x - pre > 2*k) ans++, pre = x;
        cout << ans << endl;
    }
};