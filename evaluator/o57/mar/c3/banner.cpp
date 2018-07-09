#include <bits/stdc++.h>
using namespace std;

int n, m, dp[305][305];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		dp[a][b]++;
	}
	for(int i = n-1; i != 0; --i) for(int j = i+1; j <= n; ++j) {
		int mx = 0;
		for(int k = i; k < j; ++k) mx = max(mx, dp[i][k] + dp[k+1][j]);
		dp[i][j] += mx;
	}
	printf("%d\n", m - dp[1][n]);
}