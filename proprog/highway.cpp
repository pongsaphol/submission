#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
using namespace std;

const int MAXN = 1e5 + 5;

struct data {
	int u, v, w;
	data(int u, int v, int w) : u(u), v(v), w(w) { }
	friend inline bool operator<(const data &a, const data &b) { return a.w > b.w; }
};

vector<data> E;
vector<pii> g[MAXN], rg[MAXN];
int n, m, s, t, p, ds[MAXN], dt[MAXN];

void init() {
	for(int i = 0; i < MAXN; ++i) g[i].clear(), rg[i].clear(), ds[i] = dt[i] = 1e9;
	E.clear();
}
	
void dijk(int s, int d[], vector<pii> g[]) {
	priority_queue<pii, vector<pii>, greater<pii> > Q;
	Q.emplace(d[s] = 0, s);
	while(!Q.empty()) {
		auto u = Q.top(); Q.pop();
		if(u.x != d[u.y]) continue;
		for(auto v : g[u.y]) if(d[v.x] > d[u.y] + v.y) {
			d[v.x] = d[u.y] + v.y;
			Q.emplace(d[v.x], v.x);
		}
	}
}

int solve() {
	init();
	scanf("%d %d %d %d %d", &n, &m, &s, &t, &p);
	while(m--) {
		int u, v, w; scanf("%d %d %d", &u, &v, &w);
		g[u].emplace_back(v, w);
		rg[v].emplace_back(u, w);
		E.emplace_back(u, v, w);
	}
	sort(all(E));
	dijk(s, ds, g), dijk(t, dt, rg);
	for(auto x : E) if(ds[x.u] + dt[x.v] + x.w <= p) return x.w;
	return -1;
}

int main() {
	int T; scanf("%d", &T); while(T--) printf("%d\n", solve());
}