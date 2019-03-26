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

const int N = 1005;

class cycletax {
private:
    int n, m, s, t;
    int ans = INF;
    vector<iii> E;
    vi g[N];
    bool check[N];
    int low[N], pre[N], par[N], inv[N], tmp[N], pos[N];
    void fill_level(int u, int p) {
        static int idx = 0;
        inv[low[u] = pre[u] = ++idx] = u, par[u] = p;
        for(int v : g[u]) if(!pre[v]) fill_level(v, u), low[u] = min(low[u], low[v]);
        else if(v != p) low[u] = min(low[u], pre[v]);
    }
    vector<int> vec;
    void insert(int tmp, int a, int b) {
        for(int i = 0; i < vec.size(); ++i) if(vec[i] == a) {
            if(tmp == -1) vec.insert(vec.begin() + i, b);
            else vec.insert(vec.begin() + i + 1, b);
            break;
        }
    }
    void find(int u, int p) {
        check[u] = true;
        if(u != s && u != t) {
            insert(tmp[inv[low[u]]], par[u], u);
            tmp[par[u]] = -tmp[inv[low[u]]];
        }
        for(int v : g[u]) if(!check[v]) find(v, u);
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> m;
        for(int i = 0, u, v, w; i < m; ++i) {
            cin >> u >> v >> w;
            E.emplace_back(u, v, w);
            if(w < ans) ans = w, s = u, t = v;
        }
        bool have = true;
        for(auto x : E) if(get<2>(x) == ans and have) have = false, s = get<0>(x), t = get<1>(x);
        else g[get<0>(x)].emplace_back(get<1>(x)), g[get<1>(x)].emplace_back(get<0>(x));
        g[s].emplace_back(t), g[t].emplace_back(s), reverse(all(g[s]));
        fill_level(s, 0);
        vec.emplace_back(s), vec.emplace_back(t);
        tmp[s] = -1;
        find(s, 0);
        for(int i = 0; i < n; ++i) pos[vec[i]] = i;
        cout << ans << ' ' << 1 << endl;
        for(auto x : E) {
            int u, v, w; tie(u, v, w) = x;
            if(u == s and v == t) cout << t << ' ' << s << " 1" << endl;
            else if(pos[u] < pos[v]) cout << u << ' ' << v << " 0" << endl;
            else cout << v << ' ' << u << " 0" << endl;
        }
    }
};