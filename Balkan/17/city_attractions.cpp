/*
first any path pass centroid
I build centroid tree because it collect atmost O(log n)
A[i] - d(i, j) = A[i] - d(i, centroid) - d(centroid, j)
for every centroid node I collect max(A[i] - d(i, centroid)) and second max
because if it from query subtree I will not think that node
*/
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

const int N = 3e5+1;

class city_attractions {
private:
    int n, A[N];
    long k;
    vector<int> g[N];
    bitset<N> check;
    int dep[N], d[N], dis[N][18], par[N];
    iii maxson[N][2]; // value, end node, lastson
    void find(int u, int p, int sz, pii &ret) {
        int mx = 0; d[u] = 1;
        for(int v : g[u]) if(v != p and !check[v]) {
                find(v, u, sz, ret), d[u] += d[v];
                mx = max(mx, d[v]);
            }
        mx = max(mx, sz - d[u]);
        if(mx < ret.y) ret = pii(u, mx);
    }
    int mic(int u, int p) {
        d[u] = 1;
        for(int v: g[u]) if(v != p and !check[v]) d[u] += mic(v, u);
        return d[u];
    }
    int find_centroid(int u) {
        int sz = mic(u, -1);
        int ret = -1;
        queue<int> Q; Q.emplace(u);
        while(!Q.empty()) {
            int u = Q.front(); Q.pop();
            int mx = 0;
            for(int v : g[u]) if(!check[v]) {
                    if(d[v] < d[u]) mx = max(mx, d[v]), Q.emplace(v);
                    else mx = max(mx, sz - d[u]);
                }
            if(mx <= (sz/2)) ret = u;
        }
        return ret;
    }
    void fillson(int u, int p, int depn, int rot, pii &track) {
        dis[u][depn] = dis[p][depn] + 1;
        int val = A[u] - dis[u][depn];
        if((val == track.x && track.y > u) || val > track.x) track = pii(val, u);
        for(int v : g[u]) if(v != p and !check[v]) fillson(v, u, depn, rot, track);
    }
    void centroid(int cen, int p) {
        check[cen] = true, dep[cen] = dep[p] + 1, par[cen] = p;
        maxson[cen][0] = iii(A[cen], cen, cen);
        vector<int> vec;
        for(int v : g[cen]) if(!check[v]) {
                pii now(-INF, -1);
                fillson(v, cen, dep[cen], v, now);
                int ncen = find_centroid(v);
                iii zz(now.x, now.y, ncen);
                centroid(ncen, cen);
                if(get<0>(maxson[cen][0]) < get<0>(zz) or (get<0>(maxson[cen][0]) == get<0>(zz) and get<1>(maxson[cen][0]) > get<1>(zz)))
                    swap(zz, maxson[cen][0]);
                if(get<0>(maxson[cen][1]) < get<0>(zz) or (get<0>(maxson[cen][1]) == get<0>(zz) and get<1>(maxson[cen][1]) > get<1>(zz)))
                    swap(zz, maxson[cen][1]);
            }
    }
    void solve_next(int z) {
        pii track(-INF, -1);
        vector<int> vec;
        vec.emplace_back(z);
        for(int i = z; i; i = par[i]) vec.emplace_back(i);
        for(int u = z; u; u = par[u]) {
            pii now(get<0>(maxson[u][0]), get<1>(maxson[u][0]));
            if(vec[dep[z] - dep[u]] == get<2>(maxson[u][0])) now = pii(get<0>(maxson[u][1]), get<1>(maxson[u][1]));
            now.x -= dis[z][dep[u]];
            if((now.x == track.x && track.y > now.y) || now.x > track.x) track = now;
        }
        d[z] = track.y;
    }
public:
    void solve(istream& cin, ostream& cout) {
        fill_n(maxson[0], N<<1, iii(-INF, -1, -1));
        cin >> n >> k;
        for(int i = 1; i <= n; ++i) cin >> A[i];
        for(int i = 1, u, v; i < n; ++i) {
            cin >> u >> v;
            g[u].emplace_back(v), g[v].emplace_back(u);
        }
        centroid(find_centroid(1), 0);
        for(int i = 1; i <= n; ++i) solve_next(i);
        for(int i = 1; i <= n; ++i) {
            int a, b, c; tie(a, b, c) = maxson[i][0];
            tie(a, b, c) = maxson[i][1];
        }
        memset(dep, 0, sizeof dep);
        dep[1] = 1;
        int u = 1;
        while(k) {
            if(dep[d[u]]) {
                k %= dep[u] - dep[d[u]] + 1;
                memset(dep, 0, sizeof dep);
                if(!k) break;
            }
            dep[d[u]] = dep[u] + 1;
            u = d[u], k--;
        }
        cout << u << endl;
    }
};
