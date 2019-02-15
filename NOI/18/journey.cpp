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
const int INF = 5e8+1;
const double EPS = 1e-10;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};


class journey {
private:
    int dp[10005][405];
    int n, m, h;
    vector<pii> g[10005];
    int mic(int u, int a) {
        if(a < 0) return 0;
        if(~dp[u][a]) return dp[u][a];
        int &now = dp[u][a];
        dp[u][a] = 0;
        for(auto v : g[u]) if(v.x < u) {
            now += mic(v.x, a - v.y);
            if(now > INF) break;
        }
        if(u != n-1) now += mic(u, a-1);
        if(now > INF) return now = INF;
        return now;
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> m >> h;
        for(int i = 0, v, w; i < n-1; ++i) for(int j = 0; j < h; ++j) {
            cin >> v >> w;
            g[v].emplace_back(i, w);
        }
        memset(dp, -1, sizeof dp);
        dp[0][0] = 1;
        for(int i = 0; i < m; ++i) cout << mic(n-1, i) << ' ';
        cout << endl;
    }
};