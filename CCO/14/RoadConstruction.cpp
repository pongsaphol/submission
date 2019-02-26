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

class RoadConstruction {
private:
    int n, m;
    vector<pii> E;
    int P[N], deg[N];
    bool status[N];
    int find(int u) { return P[u] = P[u] == u ? u : find(P[u]); }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> m;
        for(int i = 0, u, v; i < m; ++i) {
            cin >> u >> v;
            E.emplace_back(u, v);
        }
        for(int i = 0; i < m; ++i) {
            iota(P, P+N, 0);
            for(int j = 0; j < i; ++j) P[find(E[j].x)] = find(E[j].y);
            for(int j = i+1; j < m; ++j) P[find(E[j].x)] = find(E[j].y);
            status[i] = find(E[i].x) == find(E[i].y);
        }
        iota(P, P+N, 0);
        for(int i = 0; i < m; ++i) if(status[i]) P[find(E[i].x)] = find(E[i].y);
        for(int i = 0; i < m; ++i) if(!status[i]) deg[find(E[i].x)]++, deg[find(E[i].y)]++;
        int sum = 0;
        for(int i = 1; i <= n; ++i) sum += deg[i] == 1;
        cout << (sum + 1 >> 1) << endl;
    }
};