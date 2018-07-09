#include <cstdio>
#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>
#define input() (*istream_iterator<int>(cin))
using namespace std;

const int MAXN = 1e5 + 5;

int n, A[MAXN], dp[2][MAXN];
vector<int> g[MAXN];

void red() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
}

void dfs(int u, int p) {
	for(auto v:g[u]) if(v != p) {
		dfs(v, u);
		dp[1][u] += dp[0][v];
		dp[0][u] += max(dp[0][v], dp[1][v]);
	}
	dp[1][u] += A[u];
}

int main() {
	red();
	n = input();
	for(int i = 0; i < n; ++i) A[i] = input();
	for(int i = 1; i < n; ++i) {
		int a = input(), b = input();
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	dfs(0, 0);
	return !printf("%d\n", max(dp[0][0], dp[1][0]));
}