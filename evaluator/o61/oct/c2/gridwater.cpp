#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
#define all(x) x.begin(), x.end()
#define iii tuple<int, int, int>
using namespace std;

const int N = 2e5+5;
const int MOD = 1e9+7;

vector<pii> g[N];
int n, m, H[N], dep[N];
pii par[N][18];
vector<iii> E, del;

void init_lca(int u, int p) {
    for(int i = 1; i < 18; ++i) par[u][i] = pii(par[par[u][i-1].x][i-1].x, max(par[u][i-1].y, par[par[u][i-1].x][i-1].y));
    for(auto v : g[u]) if(v.x != p) {
        dep[v.x] = dep[u] + 1, par[v.x][0] = pii(u, v.y);
        init_lca(v.x, u);
    }
}

int get_lca(int a, int b) {
    if(dep[a] < dep[b]) swap(a, b);
    int mx = 0;
    for(int i = 17; ~i; --i) if(dep[par[a][i].x] >= dep[b])
        mx = max(mx, par[a][i].y), a = par[a][i].x;
    if(a == b) return mx;
    for(int i = 17; ~i; --i) if(par[a][i].x != par[b][i].x) {
        mx = max({mx, par[a][i].y, par[b][i].y});
        a = par[a][i].x, b = par[b][i].x;
    }
    return max({mx, par[a][0].y, par[b][0].y});
}

int main() {
    iota(H, H+N, 0);
    cin >> n >> m;
    for(int i = 1; i < 2*n; ++i) {
        int val;
        int z = (i / 2) * m;
        if(i & 1) {
            for(int j = 1; j < m; ++j) {
                cin >> val;
                E.emplace_back(val, z+j, z+j+1);
            }
        } else {
            for(int j = 1; j <= m; ++j) {
                cin >> val;
                E.emplace_back(val, z+j-m, z+j);
            }
        }
    }
    function<int(int)> find;
    find = [&](int u) { return H[u] == u ? u : find(H[u]); };
	sort(all(E));
	for(auto x : E) {
		int u, v, w; tie(w, u, v) = x;
		int a = find(u), b = find(v);
		if(a == b) del.emplace_back(x);
		else g[u].emplace_back(v, w), g[v].emplace_back(u, w), H[a] = b;
	}
	dep[0] = 0, dep[1] = 1, init_lca(1, 0);
	int ans = MOD;
	for(auto x : del) {
		int u, v, w; tie(w, u, v) = x;
		ans = min(ans, w - get_lca(u, v));
	}
	cout << ans << endl;
}
