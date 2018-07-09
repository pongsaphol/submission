#include <bits/stdc++.h>
#define long long long 
#define P pair<int, int>
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

void red() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	cin.sync_with_stdio(false);
}

int A[6005], dp[2][6005];
vector<int> g[6005];

void dfs(int u, int p) {
	for(auto v:g[u]) if(v != p) {
		dfs(v, u);
		dp[1][u] += dp[0][v];
		dp[0][u] += max(dp[1][v], dp[0][v]);
	}
	dp[1][u] += max(0, A[u]);
}

int main() {
	red();
	int n = input();
	for(int i = 1; i <= n; ++i) A[i] = input();
	for(int i = 1; i < n; ++i) {
		int a = input(), b = input();
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	dfs(1, 1);
	printf("%d\n", max(dp[0][1], dp[1][1]));
}