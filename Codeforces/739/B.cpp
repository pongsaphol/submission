#include <bits/stdc++.h>
#define long long long
#define P pair<int, int>
#define x first
#define y second
using namespace std;

const int MAXN = 2e5 + 5;

int n, A[MAXN], par[MAXN][18], dep[MAXN], ans[MAXN];
long d[MAXN];
vector<P> g[MAXN];

void dfs(int u, int p) {
	dep[u] = dep[p] + 1;
	par[u][0] = p;
	for(int i = 1; i <= 17; ++i) par[u][i] = par[par[u][i-1]][i-1];
	for(auto v : g[u]) {
		d[v.x] = d[u] + v.y;
		dfs(v.x, u);
	}
}

int mic(int u, int p) {
	for(auto v : g[u]) ans[u] += mic(v.x, u);
	return ans[u];
}

int main() {
	// freopen("r", "r", stdin);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", A + i);
	for(int i = 2; i <= n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].emplace_back(i, b);
	}
	dfs(1, 0);
	for(int i = 1; i <= n; ++i) {
		int p = i;
		for(int j = 17; j >= 0; --j) {
			if(d[i] - d[par[p][j]] <= A[i]) p = par[p][j];
		}
		ans[par[i][0]]++, ans[par[p][0]]--;
	}
	mic(1, 0);
	for(int i = 1; i <= n; ++i) printf("%d ", ans[i]);
}