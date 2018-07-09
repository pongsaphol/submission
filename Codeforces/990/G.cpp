#include <bits/stdc++.h>
#define long long long
#define pii pair<int, int>
#define vii vector<pii>
#define x first
#define y second
using namespace std;

const int N = 2e5+5;

int n, A[N], dp[N];
vector<vector<int> > g(N);
long ans[N];
bool chk[N];

int find(int u, int p, int sz, pii &ret) {
	int mx = 0; dp[u] = 1;
	for(auto v : g[u]) if(v != p and !chk[v]) {
		dp[u] += find(v, u, sz, ret);
		mx = max(mx, dp[v]);
	}
	mx = max(mx, sz - dp[u]);
	if(ret.x > mx) ret = pii(mx, u);
	return dp[u];
}

void upd(int u, int p, bool st, int val, vii &V) {
	if(st) {
		bool z = true;
		for(auto &x : V) if(x.x == val) { x.y++, z = false; break; }
		if(z) V.emplace_back(val, 1);
	} else for(auto &x : V) ans[__gcd(val, x.x)] += x.y;
	for(auto v : g[u]) if(v != p and !chk[v]) upd(v, u, st, __gcd(val, A[v]), V);
}

void solve(int u, int sz) {
	pii ret(sz, -1);
	find(u, 0, sz, ret);	
	chk[u = ret.y] = true;
	vii V;
	V.emplace_back(A[u], 1), ans[A[u]]++;
	for(auto v : g[u]) if(!chk[v]) upd(v, u, 0, A[v], V), upd(v, u, 1, __gcd(A[v], A[u]), V);
	for(auto v : g[u]) if(!chk[v]) solve(v, dp[v] < dp[u] ? dp[v] : sz - dp[u]);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", A+i);
	for(int i = 1, u, v; i < n; ++i) {
		scanf("%d %d", &u, &v);
		g[u].emplace_back(v), g[v].emplace_back(u);
	}
	solve(1, n);
	for(int i = 1; i < N; ++i) if(ans[i]) printf("%d %lld\n", i, ans[i]);
}