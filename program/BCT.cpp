#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
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

class BCT {
private:
    int n, m;
    vector<vi> g, ccs;
    int low[N], pre[N], id[N];
    bool art[N], cut[N<<1];
    void find_component(int u, int p) {
        static stack<int> S;
        static int idx = 0;
        low[u] = pre[u] = ++idx, S.emplace(u);
        int cnt = 0;
        for(int v : g[u]) if(!pre[v]) {
            find_component(v, u);
            low[u] = min(low[u], low[v]), cnt++;
            if(!p && cnt > 1 || p && low[v] >= pre[u]) art[u] = true;
            if(low[v] >= pre[u]) {
                ccs.emplace_back(vi());
                ccs.back().emplace_back(u);
                while(ccs.back().back() != v) ccs.back().emplace_back(S.top()), S.pop();
            }
        } else if(v != p) low[u] = min(low[u], pre[v]);
    }
    void gen_bctree() {
        g.clear(), g.emplace_back(vi());
        for(int i = 1; i <= n; ++i) if(art[i]) {
            cut[id[i] = g.size()] = true;
            g.emplace_back(vi());
        }
        for(auto &cc : ccs) {
            g.emplace_back(vi());
            for(int u : cc) {
                if(art[u]) g[id[u]].emplace_back(g.size() - 1), g.back().emplace_back(id[u]);
                else id[u] = g.size() - 1;
            }
        }
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> m;
        g.resize(n+1);
        for(int i = 0, u, v; i < m; ++i) {
            cin >> u >> v;
            g[u].emplace_back(v), g[v].emplace_back(u);
        }
        find_component(1, 0);
        gen_bctree();
    }
};
