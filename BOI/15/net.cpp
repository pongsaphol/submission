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

const int N = 5e5+5;

class net {
private:
    int n;
    vector<int> g[N], ans;
    void dfs(int u, int p) {
        if(g[u].size() == 1) ans.emplace_back(u);
        for(int v : g[u]) if(v != p) dfs(v, u);
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        int snode;
        for(int i = 1, u, v; i < n; ++i) {
            cin >> u >> v;
            g[u].emplace_back(v), g[v].emplace_back(u);

        }
        for(int i = 1; i <= n; ++i) if(g[i].size() > 1) snode = i;
        dfs(snode, 0);
        int m = ((int)ans.size() + 1) >> 1;
        cout << m << endl;
        if(ans.size() % 2) cout << snode << ' ' << ans[m-1] << endl;
        for(int i = 0; i+m < (int)ans.size(); ++i) cout << ans[i] << ' ' << ans[i+m] << endl;
    }
};