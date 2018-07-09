#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1<<17;

int n, m;
vector<vector<int> > g(N), comp(N);
vector<int> cycle;
bitset<N> mark, incycle;

bool find_cycle(int u, int p) {
	static stack<int> S;
	S.emplace(u);
	mark[u] = true;
	for(int v : g[u]) if(v != p) {
		if(mark[v]) {
			cycle.emplace_back(v);
			while(S.top() != v) cycle.emplace_back(S.top()), S.pop();
			return true;
		} else if(find_cycle(v, u)) return true;	
	}
	S.pop();
	return false;
}

int index_id, index_hld, id[N], rid[N], par[N], rot[N], spi[N], pos[N], dep[N];
int pos_cycle[N], step_cycle;

int build_hld(int u, int p) {
	id[u] = index_id, comp[index_id].emplace_back(u);
	par[u] = p, dep[u] = dep[p] + 1;
	pii ret(0, -1);
	int sum = 0;
	for(auto v : g[u]) if(v != p and !incycle[v]) {
		int sz = build_hld(v, u);
		sz += sum;
		if(ret.x < sz) ret = pii(sz, v);
	}
	spi[u] = ret.y;
	return ++sum;
}

void hld(int u) {
	++index_id;
	build_hld(u, 0);
	for(int z : comp[index_id]) {
		rid[z] = u;
		if(spi[par[z]] != z) for(int v = z; v != -1; v = spi[v]) rot[v] = z, pos[v] = ++index_hld;
	}
}

int t[N<<1], lz[N<<1];

void push_lazy(int p, int l, int r) {
	if(lz[p]) {
		if(lz[p] == 1) t[p] = 0;
		else t[p] = r-l+1;
		if(l != r) lz[p<<1] = lz[p<<1|1] = lz[p];
		lz[p] = 0;
	}
}

void updatet(int x, int y, int v, int p = 1, int l = 1, int r = n) {
	push_lazy(p, l, r);
	if(x <= l && r <= y) { lz[p] = v, push_lazy(p, l, r); return; }
	if(x > r || l > y || l > r) return;
	int m = (l + r) >> 1;
	updatet(x, y, v, p<<1, l, m), updatet(x, y, v, p<<1|1, m+1, r);
	t[p] = t[p<<1] + t[p<<1|1];
}

void update(int a, int b, int c) {
	while(rot[a] != rot[b]) {
		if(dep[rot[a]] < dep[rot[b]]) swap(a, b);
		updatet(pos[rot[a]], pos[a], c);
		a = par[rot[a]];
	}
	if(dep[a] < dep[b]) swap(a, b);
	updatet(pos[b]+1, pos[a], c);
}

int tcy[N<<1], lzcy[N<<1];

void push_lazycy(int p, int l, int r) {
	if(lzcy[p]) {
		if(lzcy[p] == 1) tcy[p] = 0;
		else tcy[p] = r-l+1;
		if(l != r) lzcy[p<<1] = lzcy[p<<1|1] = lzcy[p];
		lzcy[p] = 0;
	}
}

void updatetcy(int x, int y, int v, int p = 1, int l = 1, int r = step_cycle) {
	push_lazycy(p, l, r);
	if(x <= l && r <= y) { lzcy[p] = v, push_lazycy(p, l, r); return; }
	if(x > r || l > y || l > r) return;
	int m = (l + r) >> 1;
	updatetcy(x, y, v, p<<1, l, m), updatetcy(x, y, v, p<<1|1, m+1, r);
	tcy[p] = tcy[p<<1] + tcy[p<<1|1];
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0, u, v; i < n; ++i) {
		scanf("%d %d", &u, &v);
		g[u].emplace_back(v), g[v].emplace_back(u);
	}
	find_cycle(1, 0);
	for(auto x : cycle) incycle[x] = true, pos_cycle[x] = ++step_cycle;
	for(auto x : cycle) hld(x);
	for(int i = 0, u, v, c; i < m; ++i) {
		scanf("%d %d %d", &u, &v, &c);
		c = c ? c : -1;
		if(id[u] == id[v]) update(u, v, c);
		else {
			update(u, rid[u], c), update(v, rid[v], c);
			u = pos_cycle[rid[u]], v = pos_cycle[rid[v]];
			if(u > v) swap(u, v);
			int d = v - u;
			if(2*d == step_cycle) updatetcy(1, step_cycle, c);
			else if(2*d < step_cycle) updatetcy(u, v-1, c);
			else updatetcy(v, step_cycle, c), updatetcy(1, u-1, c);
		}
		printf("%d\n", 1 + t[1] + (tcy[1] > 1 ? tcy[1] - 1 : 0));
	}
}