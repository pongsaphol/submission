#include <bits/stdc++.h>
#define long long long
#define pll pair<long, long>
#define x first
#define y second
using namespace std;

const int N = 1e5+5;

int n, in[N], out[N], sz[N], pos[N];
long dp[N], A[N], B[N];
vector<int> g[N];

const int MXN = 1<<18;
const long INF = 1e18;
pll t[MXN<<1];
int chk[MXN<<1];

long get(pll x, long v) { return x.x * v + x.y; }

int getmid(int l, int r) {
	l += N, r += N;
	int m = (l + r) >> 1;
	return m - N;
}

void update(pll x, int s, int p = 1, int l = -N, int r = N) {
	if(chk[p] != s) { chk[p] = s, t[p] = x; return; }
	if(get(t[p], l) < get(x, l) && get(t[p], r) < get(x, r)) return;
	if(get(t[p], l) > get(x, l) && get(t[p], r) > get(x, r)) return void(t[p] = x);
	if(l == r) return;
	int m = getmid(l, r);
	if(get(t[p], l) > get(x, l)) swap(t[p], x);
	if(get(t[p], m) > get(x, m)) swap(t[p], x), update(x, s, p<<1, l, m);
	else update(x, s, p<<1|1, m+1, r);
}

long query(long x, int s, int p = 1, int l = -N, int r = N) {
	if(chk[p] != s) return INF;	
	long ret = get(t[p], x);
	if(l == r) return ret;
	int m = getmid(l, r);
	return min(ret, x <= m ? query(x, s, p<<1, l, m) : query(x, s, p<<1|1, m+1, r));
}

void get_sz(int u, int p) {
	static int idx = 0;
	in[u] = ++idx, pos[idx] = u, sz[u] = 1;
	if(p) g[u].erase(find(g[u].begin(), g[u].end(), p));
	for(int &v : g[u]) {
		get_sz(v, u);
		sz[u] += sz[v];
		if(sz[v] > sz[g[u][0]]) swap(v, g[u][0]);	
	}
	out[u] = idx;
}

int dfs(int u) {
	for(int v : g[u]) if(v != g[u][0]) dfs(v);
	int z = g[u].size() ? dfs(g[u][0]) : u;
	for(int v : g[u]) if(v != g[u][0]) {
		for(int i = in[v]; i <= out[v]; ++i) {
			int w = pos[i];
			update(pll(B[w], dp[w]), z);
		}
	}
	if(g[u].size()) dp[u] = query(A[u], z); 
	update(pll(B[u],dp[u]), z);
	return z;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%lld", A+i);
	for(int i = 1; i <= n; ++i)	scanf("%lld", B+i);
	for(int i = 1, u, v; i < n; ++i) {
		scanf("%d %d", &u, &v);
		g[u].emplace_back(v), g[v].emplace_back(u);
	}
	get_sz(1, 0);
	dfs(1);
	for(int i = 1; i <= n; ++i) printf("%lld ", dp[i]);
}
