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

class world_peace {
private:
    int n, m, q;
    vector<iii> E;
    vector<pii> que;
    int P[N];
    int find(int u) { return P[u] = P[u] == u ? u : find(P[u]); }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> m;
        for(int i = 0, u, v, w; i < m; ++i) {
            cin >> u >> v >> w;
            E.emplace_back(w, u, v);
        }
        cin >> q;
        for(int i = 0, a, b; i < q; ++i) {
            cin >> a >> b;
            que.emplace_back(a, b);
        }
        sort(all(E));
        int l = 0, r = m;
        while(l < r) {
            int m = l + r >> 1;
            iota(P, P+N, 0);
            bool st = true;
            for(int i = 0; i <= m; ++i) P[find(get<1>(E[i]))] = find(get<2>(E[i]));
            for(auto x : que) if(find(x.x) != find(x.y)) st = false;
            if(st) r = m;
            else l = m+1;
        }
        if(r == m) cout << "MISSION IMPOSSIBLE" << endl;
        else cout << get<0>(E[r]) << endl;
    }
};