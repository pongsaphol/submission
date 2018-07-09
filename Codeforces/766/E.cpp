#include <bits/stdc++.h>
#define long long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1e5+5;

pii cent;
int n, A[N], d[N], cbit[2][20], tbit[2][20];
bool chk[N];
long ans;
vector<vector<int> > g(N);

int dfs(int u, int p) {
	d[u] = 1;
	for(auto v : g[u]) if(v != p and !chk[v]) dfs(v, u), d[u] += d[v];
}

void find(int u, int p, int z) {
	int mx = z - d[u];
	for(auto v : g[u]) if(v != p and !chk[v]) find(v, u, z), mx = max(mx, d[v]);
	if(mx < cent.x) cent = pii(mx, u);
}

void upd(int v) {
	for(int i = 0; i < 20; ++i) tbit[(v>>i & 1)][i]++;
}

void push() {
	for(int i = 0; i < 2; ++i) for(int j = 0; j < 20; ++j) ans += (1ll << j) * cbit[i][j] * tbit[i^1][j];
	for(int i = 0; i < 2; ++i) for(int j = 0; j < 20; ++j) cbit[i^(A[cent.y]>>j&1)][j] += tbit[i][j], tbit[i][j] = 0;	
}

void print() {
	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j < 20; ++j) printf("%d ", cbit[i][j]);
		puts("");
	}
}

void walk(int u, int p, int d) {
	d ^= A[u];
	upd(d);
	for(auto v : g[u]) if(v != p and !chk[v]) walk(v, u, d);
}

void solve(int u) {
	cent = pii(N, -1);
	dfs(u, -1);
	find(u, -1, d[u]);
	u = cent.y;
	memset(cbit, 0, sizeof cbit);
	upd(0), push();
	for(auto v : g[u]) if(!chk[v]) {
		walk(v, u, 0);
		push();
	}
	chk[u] = true;
	for(auto v : g[u]) if(!chk[v]) solve(v);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", A + i), ans += A[i];
	for(int i = 1; i < n; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		g[a].emplace_back(b), g[b].emplace_back(a);
	}
	solve(1);
	printf("%lld\n", ans);
}