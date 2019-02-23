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

const int N = 3e4+5;
const int SZ = 175;

class skyscraper {
private:
    int n, m, s, t;
    set<int> g[N];
    int pre[SZ][N];
    int d[N];
    bool check[N];
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> m;
        for(int i = 0, a, b; i < m; ++i) {
            cin >> a >> b;
            g[a].emplace(b);
            if(i == 0) s = a;
            if(i == 1) t = a;
        }
        fill_n(d, N, INF);
        fill_n(pre[0], SZ*N, INF);
        priority_queue<pii, vector<pii>, greater<pii>> Q;
        Q.emplace(d[s] = 0, s);
        while(!Q.empty()) {
            int u = Q.top().y, x = Q.top().x; Q.pop();
            if(check[u]) continue; check[u] = true;
            if(u == t) {
                cout << x << endl;
                return;
            }
            for(int p : g[u]) {
                if(p < SZ) pre[p][u] = x;
                for(int i = 1, v = u-p; v >= 0; v -= p, ++i) {
                    if(p < SZ) {
                        if(pre[p][v] <= x+i) break;
                        pre[p][v] = x+i;
                    }
                    if(d[v] > x+i) Q.emplace(d[v] = x+i, v);
                }
                for(int i = 1, v = u+p; v < n; v += p, ++i) {
                    if(p < SZ) {
                        if(pre[p][v] <= x+i) break;
                        pre[p][v] = x+1;
                    }
                    if(d[v] > x+i) Q.emplace(d[v] = x+i, v);
                }
            }
        }
        cout << -1 << endl;
    }
};