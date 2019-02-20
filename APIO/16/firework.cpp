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

const int N = 3e5+5;

class firework {
private:
    int n, m, cost[N], sz[N];
    int slope[N], pos[N];
    long start[N];
    vector<int> g[N];
    priority_queue<long> Q[N];
    void dfs(int u) {
        sz[u] = 1;
        for(int &v : g[u]) {
            dfs(v);
            sz[u] += sz[v];
            if(sz[v] > sz[g[u][0]]) swap(v, g[u][0]);
        }
        if(g[u].empty()) {
            pos[u] = u;
            start[u] = cost[u], slope[u] = -1;
            Q[pos[u]].emplace(cost[u]), Q[u].emplace(cost[u]);
            return;
        }
        for(int v : g[u]) {
            slope[u] += slope[v], start[u] += start[v];
            if(v == g[u][0])
                pos[u] = pos[v];
            else while(!Q[pos[v]].empty()) {
                Q[pos[u]].emplace(Q[pos[v]].top());
                Q[pos[v]].pop();
            }
        }
        long opt1 = -1, opt2 = -1;
        while(slope[u] + (int)Q[pos[u]].size() >= 0) {
            swap(opt1, opt2);
            opt1 = Q[pos[u]].top(), Q[pos[u]].pop();
        }
        Q[pos[u]].emplace(opt1 + cost[u]), Q[pos[u]].emplace(opt2 + cost[u]);
        start[u] += cost[u];
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> m;
        for(int i = 2, par; i <= n+m; ++i) {
            cin >> par >> cost[i];
            g[par].emplace_back(i);
        }
        dfs(1);
        vector<long> vec;
        while(!Q[pos[1]].empty()) vec.emplace_back(Q[pos[1]].top()), Q[pos[1]].pop();
        vec.emplace_back(0);
        reverse(all(vec));
        for(int i = 1; slope[1]; ++i) {
            start[1] += slope[1] * (vec[i] - vec[i-1]);
            slope[1]++;
        }
        cout << start[1] << endl;
    }
};