#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1<<19;

int n, m;
vector<int> g[N];
int par[N], rot[N], spi[N], pos[N], dep[N], in[N], out[N], rps[N];

int dfs(int u, int p) {
	static int idx = 0;
	par[u] = p, dep[u] = dep[p] + 1, in[u] = ++idx;
	pii ret(0, -1); int sz = 1;
	for(int v : g[u]) if(v != p) {
		int now = dfs(v, u);
		sz += now;
		if(ret.x < now) ret = pii(now, v);
	}	
	spi[u] = ret.y, out[u] = idx;
	return sz;
}

void hld() {
	dfs(1, 0);
	for(int i = 1, idx = 0; i <= n; ++i) if(spi[par[i]] != i) 
		for(int j = i; ~j; j = spi[j]) pos[j] = ++idx, rot[j] = i; 
}

int t1[N<<1], t2[N<<1], lz1[N<<1], lz2[N<<1];

void pushlazy(int p, int l, int r, int t[], int lz[]) {
	if(!lz[p]) return;
	t[p] = lz[p];
	if(l != r) lz[p<<1] = lz[p<<1|1] = lz[p];
	lz[p] = 0;
}

template<typename T> 
void travel(int x, int y, const T &f, int t[], int lz[], int p = 1, int l = 1, int r = n) {
	pushlazy(p, l, r, t, lz);
	if(x > r || l > y) return;
	if(x <= l && r <= y) return f(p, l, r);
	int m = (l + r) >> 1;
	travel(x, y, f, t, lz, p<<1, l, m), travel(x, y, f, t, lz, p<<1|1, m+1, r);
}

int main() {
	scanf("%d", &n);
	for(int i = 1, u, v; i < n; ++i) {
		scanf("%d %d", &u, &v);
		g[u].emplace_back(v), g[v].emplace_back(u);
	}
	hld();
	scanf("%d", &m);
	for(int i = 1, a, b; i <= m; ++i) {
		scanf("%d %d", &a, &b);
		if(a == 1) travel(in[b], out[b], [&](int p, int l, int r) {lz1[p] = i, pushlazy(p, l, r, t1, lz1);}, t1, lz1);
		if(a == 2) while(b) travel(pos[rot[b]], pos[b], [&](int p, int l, int r) {lz2[p] = i, pushlazy(p, l, r, t2, lz2);}, t2, lz2), b = par[rot[b]];
		if(a == 3) {
			int x, y;
			travel(in[b], in[b], [&](int p, int l, int r) { x = t1[p]; }, t1, lz1);
			travel(pos[b], pos[b], [&](int p, int l, int r) { y = t2[p]; }, t2, lz2);
			if(x == y) puts("0");
			else puts(x > y ? "1" : "0");
		}
	}
}
