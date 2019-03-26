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

class salary {
private:
    int n;
    multiset<int> S[N];
    int inp[N], pos[N];
    vector<int> g[N];
    void dfs(int u) {
        int z = u;
        for(int &v : g[u]) {
            dfs(v);
            if(S[pos[v]].size() > S[pos[g[u][0]]].size()) swap(v, g[u][0]);
        }
        if(g[u].size()) pos[u] = pos[g[u][0]];
        for(int v : g[u]) if(v != g[u][0]) for(int x : S[pos[v]]) S[pos[u]].emplace(x);
        auto it = upper_bound(all(S[pos[u]]), inp[u]);
        if(it != S[pos[u]].end()) S[pos[u]].erase(it);
        S[pos[u]].emplace(inp[u]);
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        for(int i = 0; i < n; ++i) cin >> inp[i], pos[i] = i;
        for(int i = 1, u, v; i < n; ++i) {
            cin >> u >> v;
            g[u].emplace_back(v);
        }
        dfs(0);
        cout << (n - (int)S[pos[0]].size()) << endl;
    }
};