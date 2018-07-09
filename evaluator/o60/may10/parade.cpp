#include <bits/stdc++.h>
#define long long long
using namespace std;

const int N = 1e5+5, M = 1e9+7;

int n, sz[N];
long ans, dp[N], ftr[N], iftr[N];
vector<vector<int> > g(N);

long pluMod(long a, long b) { return (a + b) % M; }
long mulMod(long a, long b) { return (a * b) % M; }
long powMod(long x, long p) {
	long ret = 1;
	while(p) {
		if(p & 1) ret = mulMod(ret, x);
		x = mulMod(x, x);
		p >>= 1;
	}
	return ret;
}

void dfs(int u, int p) {
	sz[u] = 1, dp[u] = 1;
	for(auto v : g[u]) if(v != p) dfs(v, u), sz[u] += sz[v], dp[u] = mulMod(iftr[sz[v]], mulMod(dp[u], dp[v]));
	dp[u] = mulMod(dp[u], ftr[sz[u]-1]);
}

void mic(int u, int p, long pSz, long pDp) {
	long nSz = 1 + pSz, nDp = mulMod(iftr[pSz], pDp);
	for(auto v : g[u]) if(v != p) nSz += sz[v], nDp = mulMod(iftr[sz[v]], mulMod(nDp, dp[v]));
	ans = pluMod(ans, nDp = mulMod(nDp, ftr[n-1]));
	for(auto v : g[u]) if(v != p) mic(v, u, n - sz[v], mulMod(mulMod(mulMod(nDp, iftr[n-1]), mulMod(ftr[n-sz[v]-1], ftr[sz[v]])), powMod(dp[v], M-2)));
}

int main() {
	scanf("%d", &n);
	ftr[0] = iftr[0] = 1;
	for(int i = 1; i <= n; ++i) ftr[i] = mulMod(ftr[i-1], i), iftr[i] = powMod(ftr[i], M-2);
	for(int i = 1, u, v; i < n; ++i) {
		scanf("%d %d", &u, &v);
		g[u].emplace_back(v), g[v].emplace_back(u);
	}
	dfs(0, -1), mic(0, -1, 0, 1);
	printf("%lld\n", ans);
}