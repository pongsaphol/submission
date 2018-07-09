#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

const int MAXN = 2e5 + 5;

int n, A[MAXN], mx, dp[MAXN][2];
vector<int> g[MAXN];

void dfs(int u, int p) {
	vector<int> c2 = {0, 0, 0}, ca = {0, 0, 0};
	for(auto v : g[u]) if(v != p) {
		dfs(v, u);
		c2.emplace_back(dp[v][0]);
		ca.emplace_back(max(dp[v][0], dp[v][1]));
	}
	sort(all(c2), greater<int>());
	sort(all(ca), greater<int>());
	mx = max(mx, c2[0] + c2[1] + c2[2] + A[u]);
	mx = max(mx, ca[0] + ca[1] + A[u]);
	dp[u][0] = ca[0] + A[u];
	dp[u][1] = c2[0] + c2[1] + A[u];
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", A + i);
	for(int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	dfs(0, -1);
	printf("%d\n", mx);
}