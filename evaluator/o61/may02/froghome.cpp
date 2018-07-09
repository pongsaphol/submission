#include <bits/stdc++.h>
#define long long long
using namespace std;

const int N = 1e5+5;

int n, k, A[15], size[N], curmx, snode, cnt, dp[N], step[N];
long ans[15];
bool chk[N];
vector<int> g[N];

int dfs(int u, int p) {
	size[u] = 1;
	for(auto v : g[u]) if(!chk[v] and v != p) {
		dfs(v, u);
		size[u] += size[v];
	}
	return size[u];
}

void findsen(int u, int p, int d) {
	int mx = (d - size[u]);
	for(auto v : g[u]) if(!chk[v] and v != p) {
		findsen(v, u, d);
		mx = max(mx, size[v]);
	}
	if(mx < curmx) snode = u, curmx = mx;
}

bool f(int x) {
	if(x >= 0) {
		if(step[x] != cnt) step[x] = cnt, dp[x] = 0;
		return true;
	}
	return false;
}

void upd(int u, int p, int len, bool fill) {
	if(fill) f(len), dp[len]++;
	else for(int i = 1; i <= k; ++i) if(f(A[i]-len-1)) ans[i] += dp[A[i]-len-1];
	for(auto v : g[u]) if(v != p and !chk[v]) upd(v, u, len+1, fill);
}

void solve(int u) {
	++cnt;
	dfs(u, 1);
	curmx = size[u] + 1;
	findsen(u, -1, size[u]);
	u = snode;
	dp[0] = 1, step[0] = cnt;
	for(auto v : g[u]) if(!chk[v]) upd(v, u, 1, 0), upd(v, u, 1, 1);
	chk[u] = true;
	for(auto v : g[u]) if(!chk[v]) solve(v); 
}

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= k; ++i) scanf("%d", A+i), A[i]++;
	for(int i = 1; i < n; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		g[u].emplace_back(v), g[v].emplace_back(u);
	}
	solve(1);
	for(int i = 1; i <= k; ++i) printf("%lld\n", 2*ans[i]);
}