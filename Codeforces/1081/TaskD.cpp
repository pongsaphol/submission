#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define long long long
#define pii pair<int, int>
#define iii tuple<int, int, int>
#define x first
#define y second
using namespace std;
const long MOD = 1e9+7, LINF = 1e18 + 1e16;
const int INF = 1e9+1;
const double EPS = 1e-10;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

const int N = 1e5+5;

class TaskD {
private:
    int n, m, k;
    int pos[N];
    int par[N];
    int ans[N];
    vector<iii> vec;
    int find(int u) { return par[u] = par[u] == u ? u : find(par[u]); }
public:
    void solve(istream& cin, ostream& cout) {
        for(int i = 0; i < N; ++i) par[i] = i;
        cin >> n >> m >> k;
        for(int i = 1, val; i <= k; ++i) {
            cin >> val;
            pos[val] = i;
        }
        for(int i = 0, u, v, w; i < m; ++i) {
            cin >> u >> v >> w;
            vec.emplace_back(w, u, v);
        }
        sort(all(vec));
        int ans0;
        for(auto x : vec) {
            int w, u, v; tie(w, u, v) = x;
            int a = find(u);
            int b = find(v);
            if(a == b) continue;
            if(pos[a] && pos[b]) ans0 = w; 
            if(pos[a] && pos[b]) {
                if(!ans[pos[a]]) ans[pos[a]] = w;
                if(!ans[pos[b]]) ans[pos[b]] = w;
            }
            if(pos[a]) par[b] = a;
            else par[a] = b;
        }
        for(int i = 1; i <= k; ++i) cout << ans0 << ' ';
        cout << endl;
    }
};